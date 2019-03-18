package seg4145lab5_java.view;

import java.awt.Dimension;
import java.awt.TextField;

import javax.swing.JButton;
import javax.swing.JFrame;

import seg4145lab5_java.controller.ApplicationController;
import seg4145lab5_java.model.ApplicationModel;

public class ApplicationFrame extends JFrame {

	private MainPanel panel;
	
	public ApplicationFrame(ApplicationModel model) {
		setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		setSize(new Dimension(440, 320));
		setResizable(false);
		panel = new MainPanel(this, model);
		getContentPane().add(panel);
	}

	public JButton getButton(ButtonType type) {
		return panel.getButton(type);
	}

	public TextField getTextField(TextFieldType type) {
		return panel.getTextField(type);
	}

	public void refresh() {
		panel.refresh();
	}

	public void addController(ApplicationController controller) {
		panel.addController(controller);
	}
	
	
}
