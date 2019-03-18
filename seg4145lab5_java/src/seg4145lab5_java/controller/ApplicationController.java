package seg4145lab5_java.controller;

import seg4145lab5_java.StingrayController;
import seg4145lab5_java.model.ApplicationModel;
import seg4145lab5_java.utils.writer.Writer;

public class ApplicationController {

	private ApplicationModel model;
	private Writer writer;
	
	public ApplicationController(ApplicationModel model, Writer writer) {
		this.model = model;
		this.writer = writer;
	}
	
	public void moveForward() {
		Command command = new Command("move").param("forward").param(Float.toString(model.getMove()));
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
	}

	public void moveBackward() {
		Command command = new Command("move").param("backward").param(Float.toString(model.getMove()));
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
	}

	public void rotateClockwise() {
		Command command = new Command("rotate").param("cw").param(Float.toString(model.getRotation()));
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
	}

	public void rotateCounterClockwise() {
		Command command = new Command("rotate").param("ccw").param(Float.toString(model.getRotation()));
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
	}

	public void readTemperature() {
		Command command = new Command("read").param("temperature");
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
	}

	public void readDistance() {
		Command command = new Command("read").param("distance");
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
	}
	
	public void quit() {
		Command command = new Command("quit");
		writer.write(command.toString());
		model.pushToConsole("Sent: " + command.toString());
		StingrayController.quit();
	}

}
