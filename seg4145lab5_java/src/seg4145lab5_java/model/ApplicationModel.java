package seg4145lab5_java.model;

import java.util.ArrayList;
import java.util.List;

import seg4145lab5_java.StingrayController;

public class ApplicationModel {

	private float temperature;
	private float distance;
	private float move;
	private float rotation;
	private List<String> console;
	
	public ApplicationModel() {
		this.temperature = 0f;
		this.distance = 0f;
		this.move = 0f;
		this.rotation = 0f;
		console = new ArrayList<String>();
	}

	public float getTemperature() {
		return temperature;
	}

	public void setTemperature(float temperature) {
		this.temperature = temperature;
		StingrayController.refresh();
	}

	public float getDistance() {
		return distance;
	}

	public void setDistance(float distance) {
		this.distance = distance;
		StingrayController.refresh();
	}

	public float getMove() {
		return move;
	}

	public void setMove(float move) {
		this.move = move;
		StingrayController.refresh();
	}

	public float getRotation() {
		return rotation;
	}

	public void setRotation(float rotation) {
		this.rotation = rotation;
		StingrayController.refresh();
	}

	public List<String> getConsole() {
		return new ArrayList<String>(console);
	}

	public void pushToConsole(String msg) {
		console.add(msg);
		StingrayController.refresh();
	}

	
	
}
