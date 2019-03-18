package seg4145lab5_java.utils.writer;
import java.io.IOException;
import java.io.PrintWriter;

import seg4145lab5_java.utils.connection.Connection;

/**
 * Writes messages to Wifi.
 * 
 * @author William Gardiner (7267012)
 */
public class WifiWriter implements Writer {

	private Connection connection;
	private PrintWriter writer;
	
	public WifiWriter(Connection connection) {
		this.connection = connection;
		this.writer = null;
	}
	
	/*
	 * Initializes the stream.
	 */
	public WifiWriter init() throws IOException {
		writer = new PrintWriter(connection.getSocket().getOutputStream(), true);
		return this;
	}
	
	@Override
	public void write(String msg) {
		writer.println(msg);
	}
}
