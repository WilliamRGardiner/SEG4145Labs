package seg4145lab5_java.view;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Label;

import javax.swing.JPanel;

public class ConsoleLine extends JPanel {

	private Label label;
	
	public ConsoleLine(String text) {
		setBackground(Color.BLACK);
		setForeground(Color.WHITE);
		setSize(new Dimension(20, 220));
		label = new Label(text);
		label.setSize(new Dimension(20, 220));
	    label.setFont(new Font("Courier New", Font.BOLD, 12));
		add(label);
		
	}
	
}
