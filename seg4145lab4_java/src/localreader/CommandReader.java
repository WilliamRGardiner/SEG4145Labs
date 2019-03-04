package localreader;
import java.util.Scanner;

import command.Command;
import main.ConcurrencyHelper;

public class CommandReader implements LocalReader<Command> {

	Command[] commands;
	Scanner scanner;
	
	public CommandReader(Command[] commands) {
		this.commands = commands;
		this.scanner = new Scanner(System.in);
	}
	
	@Override
	public Command read() throws ReadException {
		try {
			ConcurrencyHelper.consoleSemaphore.acquire();
			for(int i = 0; i < commands.length; i++) {
				System.out.printf("%d - %s", i+1, commands[i].getDescription());
			}
			System.out.print("Please enter a command: ");
			
			int commandCode = scanner.nextInt();
			if(commandCode <= commands.length) {
				return commands[commandCode-1].init();
			} else {
				throw new ReadException(new IllegalArgumentException("Invalid command key"));
			}
		} catch (InterruptedException e) {
			throw new ReadException(e);
		} finally {
			ConcurrencyHelper.consoleSemaphore.release();
		}
	}

}
