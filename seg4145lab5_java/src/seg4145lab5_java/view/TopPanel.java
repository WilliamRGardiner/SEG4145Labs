package seg4145lab5_java.view;

import java.awt.TextField;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JPanel;

import seg4145lab5_java.controller.ApplicationController;
import seg4145lab5_java.model.ApplicationModel;

public class TopPanel extends JPanel {

	private ButtonPanel buttonPanel;
	private ParameterPanel paramPanel;
	
	public TopPanel(ApplicationFrame view, ApplicationModel model) {
		setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
		buttonPanel = new ButtonPanel(view);
		add(buttonPanel);
		paramPanel = new ParameterPanel(view, model);
		add(paramPanel);
	}

	public JButton getButton(ButtonType type) {
		return buttonPanel.getButton(type);
	}

	public TextField getTextField(TextFieldType type) {
		return paramPanel.getTextField(type);
	}

	public void refresh() {
		paramPanel.refresh();
	}

	public void addController(ApplicationController controller) {
		buttonPanel.addController(controller);
	}
	
}
