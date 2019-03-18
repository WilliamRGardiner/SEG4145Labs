package seg4145lab5_java.view;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.util.HashMap;
import java.util.Map;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.border.EtchedBorder;

import seg4145lab5_java.controller.ApplicationController;
import seg4145lab5_java.controller.ButtonListener;

public class ButtonPanel extends JPanel {

	ApplicationFrame view;
	Map<ButtonType, JButton> buttonMap;
	
	public ButtonPanel(ApplicationFrame view) {
		this.view = view;
		
		buttonMap = new HashMap<>();
		
		setLayout(new GridLayout(2, 3));
		setBorder(BorderFactory.createEtchedBorder(EtchedBorder.RAISED));
		setSize(new Dimension(ParameterPanel.dim.height * 2 * 3, ParameterPanel.dim.height * 2 * 2));
		
		JButton temp = new JButton(new ImageIcon("icons/temp.png"));
		temp.setPreferredSize(new Dimension(ParameterPanel.dim.height * 2, ParameterPanel.dim.height * 2));
		temp.setEnabled(false);
		buttonMap.put(ButtonType.TEMP, temp);
		add(temp);
		
		JButton forward = new JButton(new ImageIcon("icons/up.png"));
		forward.setPreferredSize(new Dimension(ParameterPanel.dim.height * 2, ParameterPanel.dim.height * 2));
		forward.setEnabled(false);
		buttonMap.put(ButtonType.UP, forward);
		add(forward);
		
		JButton dist = new JButton(new ImageIcon("icons/dist.png"));
		dist.setPreferredSize(new Dimension(ParameterPanel.dim.height * 2, ParameterPanel.dim.height * 2));
		dist.setEnabled(false);
		buttonMap.put(ButtonType.DIST, dist);
		add(dist);
		
		JButton left = new JButton(new ImageIcon("icons/left.png"));
		left.setPreferredSize(new Dimension(ParameterPanel.dim.height * 2, ParameterPanel.dim.height * 2));
		left.setEnabled(false);
		buttonMap.put(ButtonType.LEFT, left);
		add(left);
		
		JButton backward = new JButton(new ImageIcon("icons/down.png"));
		backward.setPreferredSize(new Dimension(ParameterPanel.dim.height * 2, ParameterPanel.dim.height * 2));
		backward.setEnabled(false);
		buttonMap.put(ButtonType.DOWN, backward);
		add(backward);
		
		JButton right = new JButton(new ImageIcon("icons/right.png"));
		right.setPreferredSize(new Dimension(ParameterPanel.dim.height * 2, ParameterPanel.dim.height * 2));
		right.setEnabled(false);
		buttonMap.put(ButtonType.RIGHT, right);
		add(right);
		
	}

	public JButton getButton(ButtonType type) {
		return buttonMap.get(type);
	}

	public void addController(ApplicationController controller) {
		for(ButtonType buttonType : buttonMap.keySet()) {
			JButton button = buttonMap.get(buttonType);
			button.setEnabled(true);
			button.addActionListener(new ButtonListener(controller, view));
		}
		revalidate();
		repaint();
	}
	
	
}
