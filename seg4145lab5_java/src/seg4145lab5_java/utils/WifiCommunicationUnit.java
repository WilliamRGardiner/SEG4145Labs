package seg4145lab5_java.utils;

import java.io.IOException;

import seg4145lab5_java.utils.connection.Connection;
import seg4145lab5_java.utils.reader.Reader;
import seg4145lab5_java.utils.reader.WifiReader;
import seg4145lab5_java.utils.writer.WifiWriter;
import seg4145lab5_java.utils.writer.Writer;

public class WifiCommunicationUnit extends CommunicationUnit {

	public WifiCommunicationUnit(Connection connection) throws IOException {
		super(getReader(connection), getWriter(connection));
	}
	
	private static Reader getReader(Connection connection) throws IOException {
		return new WifiReader(connection).init();
	}

	private static Writer getWriter(Connection connection) throws IOException {
		return new WifiWriter(connection).init();
	}
	
}
