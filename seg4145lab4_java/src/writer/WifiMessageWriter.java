package writer;
import java.io.IOException;
import java.io.PrintWriter;

import connection.Connection;

public class WifiMessageWriter implements MessageWriter {

	private Connection connection;
	private PrintWriter writer;
	
	public WifiMessageWriter(Connection connection) {
		this.connection = connection;
		this.writer = null;
	}
	
	public WifiMessageWriter init() throws IOException {
		writer = new PrintWriter(connection.getSender().getOutputStream(), true);
		return this;
	}
	
	@Override
	public void write(String msg) {
		writer.println(msg);
	}
}
