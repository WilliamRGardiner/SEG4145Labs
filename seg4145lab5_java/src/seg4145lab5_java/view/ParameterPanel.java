package seg4145lab5_java.view;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.TextField;
import java.util.HashMap;
import java.util.Map;

import javax.swing.BorderFactory;
import javax.swing.JPanel;
import javax.swing.border.EtchedBorder;

import seg4145lab5_java.controller.TextFieldListener;
import seg4145lab5_java.model.ApplicationModel;

public class ParameterPanel extends JPanel {

	public static Dimension dim = new Dimension(100, 20);
	
	private ApplicationModel model;
	
	private Map<TextFieldType, TextField> textFieldMap;
	private TextField moveField;
	private TextField rotateField;
	private Label distanceLabel;
	private Label temperatureLabel;
	
	public ParameterPanel(ApplicationFrame view, ApplicationModel model) {
		this.model = model;
		textFieldMap = new HashMap<>();
		
		setLayout(new GridLayout(4, 3));
		setBorder(BorderFactory.createEtchedBorder(EtchedBorder.RAISED));
		
		moveField = new TextField();
		moveField.setSize(dim);
		moveField.addFocusListener(new TextFieldListener(view, model));
		textFieldMap.put(TextFieldType.MOVEMENT, moveField);
		rotateField = new TextField();
		rotateField.setSize(dim);
		rotateField.addFocusListener(new TextFieldListener(view, model));
		textFieldMap.put(TextFieldType.ROTATION, rotateField);
		distanceLabel = new Label("0.0");
		distanceLabel.setSize(dim);
		temperatureLabel = new Label("0.0");
		temperatureLabel.setSize(dim);
		
		addField("Move", moveField, "cm");
		addField("Rotate", rotateField, "degrees");
		addField("Distance", distanceLabel, "cm");
		addField("Temperature", temperatureLabel, "degrees");
		
	}
	
	private void addField(String labelText, Component component, String unitText) {
		Label label = new Label(labelText);
		label.setSize(dim);
		add(label);
		
		add(component);
		
		Label unit = new Label(unitText);
		unit.setSize(dim);
		add(unit);
	}

	public TextField getTextField(TextFieldType type) {
		return textFieldMap.get(type);
	}

	public void refresh() {
		moveField.setText(Float.toString(model.getMove()));
		rotateField.setText(Float.toString(model.getRotation()));
		distanceLabel.setText(Float.toString(model.getDistance()));
		temperatureLabel.setText(Float.toString(model.getTemperature()));	
	}
	
}
