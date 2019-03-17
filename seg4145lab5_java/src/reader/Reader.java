package reader;

/**
 * Reads stuff. That is all.
 * 
 * @author William Gardiner (7267012)
 *
 * @param <T>
 */
public interface Reader<T> {

	/**
	 * Read a Value
	 * 
	 * @return
	 * @throws ReadException
	 */
	public T read() throws ReadException;
	
	/**
	 * Close the reader.
	 */
	public void close();
	
}
