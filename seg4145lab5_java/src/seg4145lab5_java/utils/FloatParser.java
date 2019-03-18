package seg4145lab5_java.utils;

public class FloatParser {

	public static float floatOrZero(String number) {
		float value = 0f;
		try {
			value = Float.parseFloat(number);
		} catch(NumberFormatException e) {
			
		}
		return value;
	}
	
}
