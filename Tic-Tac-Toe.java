import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import static java.lang.Thread.sleep;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.plaf.OptionPaneUI;

class TicTacToe extends Frame{
    Panel gameSpace;
    static int red=0,blue=0;    
    Panel Score,side;
    Button[] block;
    Button chance;
    int player=1;   
    int i,count=0;
    TextField scoreBlue,scoreRed,winner;
    int arr[][];
    
    TicTacToe()
    {
        setLayout(new FlowLayout(FlowLayout.CENTER, 40, 10));
        arr=new int[3][3];
        for(i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[i][j]=0;
        gameSpace=new Panel(new GridLayout(3, 3, 5, 5));
        chance=new Button("   ");
        chance.setBackground(Color.red);
        winner=new TextField("             ");
        winner.setBackground(Color.white);
        block=new Button[10];
        for(i=0;i<9;i++){
            block[i]=new Button("   ");
            block[i].setName(i+"");
            block[i].setPreferredSize(new Dimension(75,75));
            gameSpace.add(block[i]);
            block[i].addActionListener(new ActionListener(){
                @Override
                public void actionPerformed(ActionEvent e) {
                    Button b=(Button) e.getSource();
                    if(b.getBackground()!=Color.red&&b.getBackground()!=Color.blue)
                    {
                        count++;
                        if(player==1)
                        {
                        
                            b.setBackground(Color.red);
                            player=2;    
                            i=Integer.parseInt(b.getName());
                            changearr(i,1);
                            chance.setBackground(Color.blue);
                        }
                        else 
                        {   
                            b.setBackground(Color.BLUE);
                            chance.setBackground(Color.red);
                            i=Integer.parseInt(b.getName());
                            changearr(i,2);
                            player=1;
                        }
                        if(count==9)
                        {
                            winner.setText("Game Draw");
                            try {
                                sleep(2000);
                            } catch (InterruptedException ex) {
                                Logger.getLogger(TicTacToe.class.getName()).log(Level.SEVERE, null, ex);
                            }
                            setVisible(false);
                            new TicTacToe();
                        }
                    }
                }
            
        });
        }
        add(gameSpace);
        
        Panel Chance=new Panel();
        side=new Panel(new BorderLayout(5,10));
        Chance.add(new Label("Player "),BorderLayout.NORTH);
        Chance.add(chance,BorderLayout.NORTH);
        side.add(Chance,BorderLayout.NORTH);
        Score=new Panel();
        Score.add(new Label("Red"));
        Score.add(new Label(red+""));
        Score.add(new Label("Blue"));
        Score.add(new Label(blue+""));
        side.add(Score,BorderLayout.CENTER);
        winner.setEditable(false);
        winner.setText("            Let's Play!!");
        side.add(winner,BorderLayout.SOUTH);
        add(side);
        
        setVisible(true);
        setTitle("Tic-Tac-Toe");
        setSize(500,400);
        
        addWindowListener(new WindowAdapter(){
            @Override
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });
        //add(new Label("Created by Aditya Vijayvergia"));
        
            
    }
    
    public void changearr(int i,int c)
    {
        if(i>5)
        {
            arr[2][i-6]=c;
            ifWin(2,i-6,c);
        }
        else
            if(i>2)
            {
                arr[1][i-3]=c;
                ifWin(1,i-3,c);
            }
        else
            {
                arr[0][i]=c;
                ifWin(0,i,c);
            }
    }

    public void ifWin(int i1,int j1,int c)
    {
        int p=0;
        int i=i1,j=j1;
        while(i<3)
        {
            if(arr[i][j]==c)
                p++;
            i++;
        }
        i=i1;j=j1;
        while(i>=0)
        {
            if(arr[i][j]==c)
                p++;
            i--;
        }
        if(p==4)
        {
            
            winner(c);
        }
        p=0;
        i=i1;j=j1;
        while(j<3)
        {
            if(arr[i][j]==c)
                p++;
            j++;
        }
        i=i1;j=j1;
        while(j>=0)
        {
            if(arr[i][j]==c)
                p++;
            j--;
        }
        if(p==4)
        {
           winner(c);
        }
        p=0;
        i=i1;j=j1;
        
        while(i<3&&j<3)
        {
            if(arr[i][j]==c)
                p++;
            i++;j++;
        }
        i=i1;j=j1;
        while(i>-1&&j>-1)
        {
             if(arr[i][j]==c)
                p++;
             i--;j--;
        }
        if(p==4)
        {
            winner(c);
        }
        p=0;
        i=i1;j=j1;
        
        while(i>=0&&j<3)
        {
            if(arr[i][j]==c)
                p++;
            i--;
            j++;
        }
        i=i1;j=j1;
         while(i<3&&j>=0)
        {
            if(arr[i][j]==c)
                p++;
            i++;
            j--;
        }
        if(p==4)
        {
            winner(c);
        }
    }
    
    public void winner(int i)
    {
        count=0; 
        if(i==1)
        {
                winner.setText("red wins");
                red++;
        }
            else
        {
            blue++;    
            winner.setText("blue wins");
        }
        winner.setBackground(Color.yellow);
        try {
            sleep(2000);
        } catch (InterruptedException ex) {
            Logger.getLogger(TicTacToe.class.getName()).log(Level.SEVERE, null, ex);
        }
        winner.setVisible(false);
        setVisible(false);
        new TicTacToe();
    }
    
   
    public static void main(String[] args) {
        new TicTacToe();
    }
    
}
