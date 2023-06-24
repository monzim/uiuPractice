
/**
 * CalCulateMotgage
 */
public class CalCulateMotgage {
    final byte TOTAL_MONTHS = 12;

    public float calculateMotgage(float total_amount, float interest_rate, int years) {
        float motgage = 0.0f;
        float monthly_interest_rate = interest_rate / 100 / TOTAL_MONTHS;
        int total_months = years * TOTAL_MONTHS;

        motgage = (float) (total_amount * monthly_interest_rate * Math.pow(1 + monthly_interest_rate, total_months)
                / (Math.pow(1 + monthly_interest_rate, total_months) - 1));

        return motgage;
    }

}