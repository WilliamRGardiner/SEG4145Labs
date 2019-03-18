package seg4145lab5_java.utils;

import java.sql.Timestamp;
import java.util.Date;

public class TimeGetter {

	public static String getTimestamp() {
		Date date= new Date();
		long time = date.getTime();
		Timestamp timestamp = new Timestamp(time);
		return timestamp.toString();
	}
	
}
