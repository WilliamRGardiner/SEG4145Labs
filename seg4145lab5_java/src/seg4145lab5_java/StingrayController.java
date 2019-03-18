package seg4145lab5_java;

import java.io.IOException;

import seg4145lab5_java.controller.ApplicationController;
import seg4145lab5_java.model.ApplicationModel;
import seg4145lab5_java.utils.connection.Connection;
import seg4145lab5_java.utils.writer.WifiWriter;
import seg4145lab5_java.utils.writer.Writer;
import seg4145lab5_java.view.ApplicationFrame;

public class StingrayController {
	private static ApplicationFrame view;
	
	public static void main(String[] args) {
		
		ApplicationModel model = new ApplicationModel();

		view = new ApplicationFrame(model);
		view.setVisible(true);

		model.pushToConsole("Starting up...");
		Connection connection = null;
		Writer writer= null;
		try {
			model.pushToConsole("Waiting for connection...");
			connection = new Connection(9876).connect();
			writer = new WifiWriter(connection).init();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		model.pushToConsole("Connected!");
		view.addController(new ApplicationController(model, writer));

		model.pushToConsole("Ready!");
	}
	
	public static void refresh() {
		view.refresh();
	}

	public static void quit() {
		view.dispose();
		System.exit(0);
	}
	
}
