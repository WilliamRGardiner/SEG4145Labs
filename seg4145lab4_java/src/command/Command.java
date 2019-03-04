package command;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Command {

	private static final String MAIN_SEPERATOR = ": ";
	private static final String PARAM_SEPERATOR = ", ";
	private static final String TERMINATOR = ".";
	
	private String main;
	private List<String> parameterValues;
	private List<String> parameterNames;
	private String description;
	private String message;
	
	public static class Builder {
		
		private String main;
		private List<String> parameterValues;
		private List<String> parameterNames;
		private String description;
		
		public Builder(String main, String description) {
			this.main = main;
			this.description = description;
			this.parameterValues = new ArrayList<String>();
			this.parameterNames = new ArrayList<String>();
		}
		
		public Builder addParameterValue(String value) {
			parameterValues.add(value);
			return this;
		}
		
		public Builder addParameterName(String name) {
			parameterNames.add(name);
			return this;
		}
		
		public Command build() {
			return new Command(main, parameterValues, parameterNames, description);
		}
	}
	
	private Command(String main, List<String> parameterValues, List<String> parameterNames, String description) {
		this.main = main;
		this.parameterValues = parameterValues;
		this.parameterNames = parameterNames;
		this.description = description;
	}
	
	public String getDescription() {
		return description;
	}
	
	public Command init(Scanner scanner) {
		StringBuilder stringBuilder = new StringBuilder();
		stringBuilder = stringBuilder.append(main);
		if(parameterValues.size() == 0 && parameterNames.size() == 0) {
			message = stringBuilder.append(TERMINATOR).toString();
			return this;
		} else {
			stringBuilder = stringBuilder.append(MAIN_SEPERATOR);
		}
		
		for(String param : parameterValues) {
			stringBuilder = stringBuilder.append(param).append(PARAM_SEPERATOR);
		}
		
		for(String paramName : parameterNames) {
			System.out.printf("Please enter %s: ", paramName);
			stringBuilder.append(scanner.next()).append(PARAM_SEPERATOR);
		}
		
		stringBuilder.delete(stringBuilder.length() - PARAM_SEPERATOR.length(), stringBuilder.length());
		message = stringBuilder.append(TERMINATOR).toString();
		return this;
	}
	
	public String toString() {
		return message;
	}
}
