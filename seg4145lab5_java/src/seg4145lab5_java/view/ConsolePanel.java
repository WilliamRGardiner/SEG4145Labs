package seg4145lab5_java.view;

import java.awt.Color;
import java.awt.Dimension;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JPanel;
import javax.swing.border.EtchedBorder;

import seg4145lab5_java.model.ApplicationModel;

public class ConsolePanel extends JPanel {

	private ApplicationModel model;
	
	public ConsolePanel(ApplicationModel model) {
		this.model = model;
		
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		setBackground(Color.BLACK);
		setSize(new Dimension(220, 80));
		setBorder(BorderFactory.createEtchedBorder(EtchedBorder.RAISED));
		
		String[] lines = new String[4];
		
		for(int i = 0; i < 4; i++) {
			lines[i] = "";
		}
		
		displayLines(lines);
		
	}
	
	private void displayLines(String[] lines) {
		removeAll();
		revalidate();
		repaint();
		for(int i = 3; i >= 0; i--) {
			add(new ConsoleLine(lines[i]));
		}
	}

	public void refresh() {
		String[] lines = new String[4];
		
		for(int i = 0; i < 4; i++) {
			if(i < model.getConsole().size()) {
				lines[i] = model.getConsole().get(model.getConsole().size() - i - 1);
			} else {
				lines[i] = "";
			}
		}
		
		displayLines(lines);
	}
	
}
