package writer;
import java.io.IOException;
import java.io.PrintWriter;

import connection.Connection;

/**
 * Writes messages to Wifi.
 * 
 * @author William Gardiner (7267012)
 */
public class WifiMessageWriter implements MessageWriter {

	private Connection connection;
	private PrintWriter writer;
	
	public WifiMessageWriter(Connection connection) {
		this.connection = connection;
		this.writer = null;
	}
	
	/*
	 * Initializes the stream.
	 */
	public WifiMessageWriter init() throws IOException {
		writer = new PrintWriter(connection.getSender().getOutputStream(), true);
		return this;
	}
	
	@Override
	public void write(String msg) {
		writer.println(msg);
	}
}
