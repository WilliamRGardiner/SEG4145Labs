package reader;

public class ConsoleWriterCallback implements Callback {

	@Override
	public void callback(String message) {
		System.out.println("Message Recieved: " + message);
	}

}
