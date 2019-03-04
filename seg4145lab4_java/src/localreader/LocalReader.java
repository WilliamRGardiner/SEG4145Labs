package localreader;

import command.Command;

public interface LocalReader<T> {

	public Command read() throws ReadException;
	public void close();
	
}
