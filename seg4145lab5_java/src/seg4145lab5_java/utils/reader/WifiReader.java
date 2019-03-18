package seg4145lab5_java.utils.reader;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import seg4145lab5_java.utils.connection.Connection;

public class WifiReader implements Reader {

	private Connection connection;
	private BufferedReader reader;
	
	public WifiReader(Connection connection) {
		this.connection = connection;
		this.reader = null;
	}
	
	/*
	 * Initializes the stream.
	 */
	public WifiReader init() throws IOException {
		reader = new BufferedReader(new InputStreamReader(connection.getSocket().getInputStream()));
		return this;
	}
	
	@Override
	public String read() throws IOException {
		char[] buffer = new char[20];
		int size = reader.read(buffer);
		char[] trimedBuffer = new char[size];
		for(int i = 0; i < size; i++) {
			trimedBuffer[i] = buffer[i];
		}
		return new String(trimedBuffer);
	}

}
