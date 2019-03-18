package seg4145lab5_java.controller;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import seg4145lab5_java.view.ApplicationFrame;
import seg4145lab5_java.view.ButtonType;

public class ButtonListener implements ActionListener {

	private ApplicationController controller;
	private ApplicationFrame view;
	
	public ButtonListener(ApplicationController controller, ApplicationFrame view) {
		this.view = view;
		this.controller = controller;
	}
	
	@Override
	public void actionPerformed(ActionEvent event) {
		
		Object source = event.getSource();
		
		if(source == view.getButton(ButtonType.UP)) {
			controller.moveForward();
		} else if(source == view.getButton(ButtonType.DOWN)) {
			controller.moveBackward();
		} else if(source == view.getButton(ButtonType.LEFT)) {
			controller.rotateCounterClockwise();
		} else if(source == view.getButton(ButtonType.RIGHT)) {
			controller.rotateClockwise();
		} else if(source == view.getButton(ButtonType.TEMP)) {
			controller.readTemperature();
		} else if(source == view.getButton(ButtonType.DIST)) {
			controller.readDistance();
		} 
		
	}

}
