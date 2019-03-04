package connection;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Connection {

	private int port;
	private Socket sender;
	private ServerSocket reciever;
	
	public Connection(int port) {
		this.port = port;
		this.sender = null;
		this.reciever = null;
	}
	
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
