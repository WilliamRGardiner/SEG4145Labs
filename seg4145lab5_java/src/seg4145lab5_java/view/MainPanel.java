package seg4145lab5_java.view;

import java.awt.Dimension;
import java.awt.TextField;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JPanel;

import seg4145lab5_java.controller.ApplicationController;
import seg4145lab5_java.model.ApplicationModel;

public class MainPanel extends JPanel {

	private TopPanel controlPanel;
	private ConsolePanel consolePanel;
	
	public MainPanel(ApplicationFrame view, ApplicationModel model) {
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		controlPanel = new TopPanel(view, model);
		add(controlPanel);
		consolePanel = new ConsolePanel(model);
		add(consolePanel);
	}

	public JButton getButton(ButtonType type) {
		return controlPanel.getButton(type);
	}

	public TextField getTextField(TextFieldType type) {
		return controlPanel.getTextField(type);
	}

	public void refresh() {
		controlPanel.refresh();
		consolePanel.refresh();
	}

	public void addController(ApplicationController controller) {
		controlPanel.addController(controller);
	}
	
}
