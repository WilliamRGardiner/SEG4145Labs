package seg4145lab5_java;

import java.io.IOException;

import seg4145lab5_java.controller.ApplicationController;
import seg4145lab5_java.model.ApplicationModel;
import seg4145lab5_java.utils.CommunicationUnit;
import seg4145lab5_java.utils.WifiCommunicationUnit;
import seg4145lab5_java.utils.WindowCloser;
import seg4145lab5_java.utils.connection.Connection;
import seg4145lab5_java.view.ApplicationFrame;

public class StingrayController {
	private static ApplicationFrame view;
	
	public static void main(String[] args) {
		
		ApplicationModel model = new ApplicationModel();

		view = new ApplicationFrame(model);
		view.addWindowListener(new WindowCloser());
		view.setVisible(true);

		model.pushToConsole("Starting up...");
		Connection connection = null;
		CommunicationUnit comms= null;
		try {
			model.pushToConsole("Waiting for connection...");
			connection = new Connection(9876).connect();
			comms = new WifiCommunicationUnit(connection);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		model.pushToConsole("Connected!");
		view.addController(new ApplicationController(model, comms));

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
