package seg4145lab5_java.utils;

import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import seg4145lab5_java.StingrayController;

public class WindowCloser extends WindowAdapter {
	
	@Override
	public void windowClosing(WindowEvent e) {
		StingrayController.quit();
	}
	
}
