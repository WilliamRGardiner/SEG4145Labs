package main;

import java.util.ArrayList;
import java.util.List;

import command.Command;
import connection.Connection;
import localreader.CommandReader;
import localreader.LocalReader;
import localreader.ReadException;
import writer.MessageWriter;
import writer.WifiMessageWriter;

public class StingrayCommandTerminal {

	private static int PORT = 9876;
	
	public static void main(String[] args) {
		Connection connection = new Connection(PORT);
		MessageWriter writer = new WifiMessageWriter(connection);
//		Reader reader = new WifiReader(connection);
		for(;;) {
			List<Command> commands = new ArrayList<Command>();
			commands.add(new Command.Builder("move", "Move the robot forward.")
					.addParameterValue("forward")
					.addParameterName("distance (cm)")
					.build());
			commands.add(new Command.Builder("move", "Move the robot backward.")
					.addParameterValue("backward")
					.addParameterName("distance (cm)")
					.build());
			commands.add(new Command.Builder("rotate", "Rotate the robot clockwise.")
					.addParameterValue("cw")
					.addParameterName("degrees")
					.build());
			commands.add(new Command.Builder("rotate", "Rotate the robot counter clockwise.")
					.addParameterValue("ccw")
					.addParameterName("degrees")
					.build());
			commands.add(new Command.Builder("read", "Read the distance to the nearest object.")
					.addParameterValue("distance")
					.build());
			commands.add(new Command.Builder("read", "Read the Temperature.")
					.addParameterValue("temperature")
					.build());
			Command quit = new Command.Builder("quit", "Quit!").build();
			commands.add(quit);
			LocalReader commandReader = new CommandReader(commands.toArray(new Command[commands.size()]));
			
			Command command;
			try {
				command = commandReader.read();
			} catch (ReadException e) {
				System.out.println("Read Error");
				continue;
			}
			
			writer.write(command.toString());


			if(command == quit) {
				break;
			}
			
			// Uncomment when ready to read.
			// reader.readNext(new ConsoleWriterCallback());
			
			
		}
		
	}
	
}
