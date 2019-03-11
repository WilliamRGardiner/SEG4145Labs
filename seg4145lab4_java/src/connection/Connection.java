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
	private ServerSocket reciever;
	
	public Connection(int port) {
		this.port = port;
		this.sender = null;
		this.reciever = null;
	}
	
	/**
	 * Initializes the connection.
	 * 
	 * @return
	 * @throws IOException
	 */
	public Connection connect() throws IOException {
		reciever = new ServerSocket(port);
		sender = reciever.accept();
		return this;
	}
	
	public boolean isConnected() {
		return sender != null;
	}

	public Socket getSender() {
		return sender;
	}

	public ServerSocket getReciever() {
		return reciever;
	}
	
}
