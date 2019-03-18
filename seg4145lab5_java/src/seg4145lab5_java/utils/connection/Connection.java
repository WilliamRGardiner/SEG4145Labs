package seg4145lab5_java.utils.connection;
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
	private Socket socket;
	private ServerSocket serverSocket;
	
	public Connection(int port) {
		this.port = port;
		this.socket = null;
		this.serverSocket = null;
	}
	
	/**
	 * Initializes the connection.
	 * 
	 * @return
	 * @throws IOException
	 */
	public Connection connect() throws IOException {
		serverSocket = new ServerSocket(port);
		socket = serverSocket.accept();
		return this;
	}
	
	public boolean isConnected() {
		return socket != null;
	}

	public Socket getSocket() {
		return socket;
	}

	public ServerSocket getServerSocket() {
		return serverSocket;
	}
	
}
