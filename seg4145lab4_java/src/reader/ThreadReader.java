package reader;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import connection.Connection;
import main.ConcurrencyHelper;

public class ThreadReader implements Runnable {

	private static final int BUFFER_SIZE = 20;
	
	private Connection connection;
	private Callback callback;

	public ThreadReader(Connection connection, Callback callback) {
		this.callback = callback;
		this.connection = connection;
	}

	@Override
	public void run() {
		char[] buffer = new char[BUFFER_SIZE];
		BufferedReader reader = null;
		try {
			ConcurrencyHelper.consoleSemaphore.acquire();
			reader = new BufferedReader(new InputStreamReader(connection.getSender().getInputStream()));
			reader.read(buffer);
			callback.callback(buffer.toString());
		} catch (IOException e) {
			System.out.println("Failed to establish reader on port.");
		} catch (InterruptedException e) {
			System.out.println("Failed to aquire console semaphore.");
		} finally {
			if(reader != null) {
				try {
					reader.close();
				} catch (IOException e) {
					System.out.println("Failed to close reader on port.");
				}
			}
			ConcurrencyHelper.consoleSemaphore.release();
		}

	}

}
