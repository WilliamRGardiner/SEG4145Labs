package seg4145lab5_java.utils;

import java.io.IOException;

import seg4145lab5_java.utils.reader.Reader;
import seg4145lab5_java.utils.writer.Writer;

public class CommunicationUnit implements Reader, Writer {

	private Reader reader;
	private Writer writer;
	
	public CommunicationUnit(Reader reader, Writer writer) {
		this.reader = reader;
		this.writer = writer;
	}
	
	@Override
	public void write(String msg) {
		writer.write(msg);
	}

	@Override
	public String read() throws IOException {
		return reader.read();
	}

	
	
}
