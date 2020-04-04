CREATE OR REPLACE FUNCTION printing_upsert_trigger() RETURNS TRIGGER AS $printing_upsert_trigger$
    DECLARE
        to_print INTEGER;
        total_printed INTEGER;
        total_delivered INTEGER;
    BEGIN
        SELECT INTO
            total_printed, to_print
            SUM(printing."printedCount"), SUM(printing.count)
        FROM printing where "orderId" = NEW."orderId";


        SELECT INTO
            total_delivered
            COALESCE(SUM(count), 0)
        FROM printing
        WHERE "orderId" =  NEW."orderId" AND "deliveryDate" IS NOT NULL;

        UPDATE "order"
          SET "printedCount" = total_printed, "pendingPrintCount" = to_print-total_printed, "deliveryCount" = total_delivered
          WHERE "id" = NEW."orderId";

        RETURN NULL;
    END;
$printing_upsert_trigger$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION printing_delete_trigger() RETURNS TRIGGER AS $printing_delete_trigger$
    DECLARE
        to_print INTEGER;
        total_printed INTEGER;
        total_delivered INTEGER;
    BEGIN
        SELECT INTO
            total_printed, to_print
            SUM(printing."printedCount"), SUM(printing.count)
        FROM printing
        WHERE "orderId" = OLD."orderId";

        SELECT INTO
            total_delivered
            COALESCE(SUM(count), 0)
        FROM printing
        WHERE "orderId" = OLD."orderId" AND "deliveryDate" IS NOT NULL;

        UPDATE "order"
          SET "printedCount" = total_printed, "pendingPrintCount" = to_print-total_printed, "deliveryCount" = total_delivered
          WHERE "id" = OLD."orderId";

        RETURN NULL;
    END;
$printing_delete_trigger$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS printing_delete_trigger on printing;
DROP TRIGGER IF EXISTS printing_upsert_trigger on printing;


CREATE TRIGGER printing_delete_trigger
AFTER DELETE ON printing
    FOR EACH ROW EXECUTE PROCEDURE printing_delete_trigger();

CREATE TRIGGER printing_upsert_trigger
AFTER INSERT OR UPDATE ON printing
    FOR EACH ROW EXECUTE PROCEDURE printing_upsert_trigger();
