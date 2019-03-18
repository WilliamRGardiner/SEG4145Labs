package seg4145lab5_java.controller;

import java.util.ArrayList;
import java.util.List;

public class Command {

	private static final String MAIN_SEPERATOR = ":";
	private static final String PARAM_SEPERATOR = ",";
	private static final String TERMINATOR = ".";

	private String base;
	private List<String> params;
	
	public Command(String base) {
		this.base = base;
		this.params = new ArrayList<>();
	}
	
	public Command param(String param) {
		this.params.add(param);
		return this;
	}
	
	public String toString() {
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder = stringBuilder.append(base);
		if(params.size() != 0) {
			stringBuilder = stringBuilder.append(MAIN_SEPERATOR);
			for(String param : params) {
				stringBuilder = stringBuilder.append(param).append(PARAM_SEPERATOR);
			}
			
			stringBuilder.delete(stringBuilder.length() - PARAM_SEPERATOR.length(), stringBuilder.length());
		}
		return stringBuilder.append(TERMINATOR).toString();
	}
	
}
