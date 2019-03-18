package seg4145lab5_java.controller.listener;

import java.awt.TextField;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import seg4145lab5_java.model.ApplicationModel;
import seg4145lab5_java.utils.FloatParser;
import seg4145lab5_java.view.ApplicationFrame;
import seg4145lab5_java.view.TextFieldType;

public class TextFieldListener implements FocusListener {
	
	private ApplicationFrame view;
	private ApplicationModel model;
	
	public TextFieldListener(ApplicationFrame view, ApplicationModel model) {
		this.view = view;
		this.model = model;
	}

	@Override
	public void focusGained(FocusEvent event) {
		TextField source = (TextField) event.getSource();		
		source.setText("");
	}

	@Override
	public void focusLost(FocusEvent event) {
		
		TextField source = (TextField) event.getSource();
		String text = source.getText().toString();
		
		float value = FloatParser.floatOrZero(text);
		
		if(source == view.getTextField(TextFieldType.MOVEMENT)) {
			model.setMove(value);
		} else if(source == view.getTextField(TextFieldType.ROTATION)) {
			model.setRotation(value);
		}
		
		
		
	}
	
}
