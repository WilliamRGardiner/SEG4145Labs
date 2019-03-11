package main;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import command.Command;
import connection.Connection;
import reader.CommandReader;
import reader.Reader;
import reader.ReadException;
import writer.MessageWriter;
import writer.WifiMessageWriter;

/**
 * The main class.
 * 
 * @author William Gardiner (7267012)
 *
 */
public class StingrayCommandTerminal {

	private static int PORT = 9876;
	
	/**
	 * Get input from user and send it to the stingray.
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("Starting...");
		MessageWriter writer = null;
		try {
			System.out.printf("Establishing Connection... ");
			Connection connection = new Connection(PORT).connect();
			System.out.println("Done!");
			System.out.printf("Initializing Writer... ");
			writer = new WifiMessageWriter(connection).init();
			System.out.println("Done!");
		} catch (IOException e1) {
			System.out.println("Init Failed");
		}
		
		System.out.println("Ready!");
		
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
		Reader<Command> commandReader = new CommandReader(commands.toArray(new Command[commands.size()]));
		
		for(;;) {
			
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
			
		}
		System.out.printf("Closing... ");
		commandReader.close();
		System.out.println("Done!");
		
	}
	
}
