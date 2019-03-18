package seg4145lab5_java.controller;

import java.io.IOException;

import seg4145lab5_java.StingrayController;
import seg4145lab5_java.model.ApplicationModel;
import seg4145lab5_java.utils.CommunicationUnit;
import seg4145lab5_java.utils.FloatParser;

public class ApplicationController {

	private ApplicationModel model;
	private CommunicationUnit comms;
	
	public ApplicationController(ApplicationModel model, CommunicationUnit comms) {
		this.model = model;
		this.comms = comms;
	}
	
	public void moveForward() {
		Command command = new Command("move").param("forward").param(Float.toString(model.getMove()));
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		String received = "";
		try {
			received = comms.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		model.pushToConsole("Received: " + received);
	}

	public void moveBackward() {
		Command command = new Command("move").param("backward").param(Float.toString(model.getMove()));
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		String received = "";
		try {
			received = comms.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		model.pushToConsole("Received: " + received);
	}

	public void rotateClockwise() {
		Command command = new Command("rotate").param("cw").param(Float.toString(model.getRotation()));
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		String received = "";
		try {
			received = comms.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		model.pushToConsole("Received: " + received);
	}

	public void rotateCounterClockwise() {
		Command command = new Command("rotate").param("ccw").param(Float.toString(model.getRotation()));
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		String received = "";
		try {
			received = comms.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		model.pushToConsole("Received: " + received);
	}

	public void readTemperature() {
		Command command = new Command("read").param("temperature");
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		String received = "";
		try {
			received = comms.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		model.pushToConsole("Received: " + received);
		float temperature = FloatParser.floatOrZero(received);
		model.setTemperature(temperature);
	}

	public void readDistance() {
		Command command = new Command("read").param("distance");
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		String received = "";
		try {
			received = comms.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		model.pushToConsole("Received: " + received);
		float distance = FloatParser.floatOrZero(received);
		model.setDistance(distance);
	}
	
	public void quit() {
		Command command = new Command("quit");
		comms.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		StingrayController.quit();
	}

}
