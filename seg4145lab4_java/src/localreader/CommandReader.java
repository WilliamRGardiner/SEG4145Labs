package localreader;
import java.util.Scanner;

import command.Command;

public class CommandReader implements LocalReader<Command> {

	private Command[] commands;
	private Scanner scanner;
	
	public CommandReader(Command[] commands) {
		this.commands = commands;
		this.scanner = new Scanner(System.in);
	}
	
	@Override
	public Command read() throws ReadException {
		for(int i = 0; i < commands.length; i++) {
			System.out.printf("%d - %s\n", i+1, commands[i].getDescription());
		}
		System.out.print("Please enter a command: ");
		int commandCode = scanner.nextInt();
		if(commandCode <= commands.length) {
			return commands[commandCode-1].init(scanner);
		} else {
			throw new ReadException(new IllegalArgumentException("Invalid command key"));
		}
	}

	public void close() {
		scanner.close();
	}
	
}
