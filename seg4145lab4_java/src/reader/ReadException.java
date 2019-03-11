package reader;

/**
 * Exception thrown when a read fails.
 * 
 * @author William Gardiner (7267012)
 *
 */
public class ReadException extends Exception {
	public ReadException(Throwable t) {
		super(t);
	}
}
