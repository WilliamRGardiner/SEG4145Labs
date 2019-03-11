package connection;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Stores information about the connection.
 * 
 * @author William Gardiner (7267012)
 *
 */
public class Connection {

	private int port;
	private Socket sender;
	private ServerSocket receiver;
	
	public Connection(int port) {
		this.port = port;
		this.sender = null;
		this.receiver = null;
	}
	
	/**
	 * Initializes the connection.
	 * 
	 * @return
	 * @throws IOException
	 */
	public Connection connect() throws IOException {
		receiver = new ServerSocket(port);
		sender = receiver.accept();
		return this;
	}
	
	public boolean isConnected() {
		return sender != null;
	}

	public Socket getSender() {
		return sender;
	}

	public ServerSocket getReciever() {
		return receiver;
	}
	
}
