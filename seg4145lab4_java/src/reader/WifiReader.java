package reader;

import connection.Connection;

public class WifiReader implements Reader {
	
	private Connection connection;
	
	public WifiReader(Connection connection) {
		this.connection = connection;
	}
	@Override
	public void readNext(Callback callback) {
		new Thread(new ThreadReader(connection, callback)).start();
	}
	
	
	
}
