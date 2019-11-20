package Vistas;
import Clases.IP;

public class Principal extends javax.swing.JFrame {
    Despliegue_info a;    
    public Principal() {
        initComponents();
        setLocationRelativeTo(null);
        setSize(460,330);
        setTitle("Recepción de IP");
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel7 = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        Confirmar = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        Uno = new javax.swing.JTextField();
        Dos = new javax.swing.JTextField();
        Tres = new javax.swing.JTextField();
        Cuatro = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();

        jLabel7.setFont(new java.awt.Font("sansserif", 1, 18)); // NOI18N
        jLabel7.setText(" .");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(0, 102, 102));
        setMinimumSize(new java.awt.Dimension(373, 265));
        getContentPane().setLayout(null);

        jLabel1.setFont(new java.awt.Font("Arial", 1, 36)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 51, 51));
        jLabel1.setText("Analizador de IP");
        getContentPane().add(jLabel1);
        jLabel1.setBounds(90, 40, 310, 43);

        Confirmar.setText("Confirmar");
        Confirmar.setCursor(new java.awt.Cursor(java.awt.Cursor.TEXT_CURSOR));
        Confirmar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ConfirmarActionPerformed(evt);
            }
        });
        getContentPane().add(Confirmar);
        Confirmar.setBounds(160, 240, 120, 28);

        jLabel2.setForeground(new java.awt.Color(0, 0, 51));
        jLabel2.setText("Me permite su IP por favor?");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(140, 140, 160, 16);
        getContentPane().add(Uno);
        Uno.setBounds(33, 177, 70, 28);
        getContentPane().add(Dos);
        Dos.setBounds(130, 177, 71, 28);
        getContentPane().add(Tres);
        Tres.setBounds(228, 177, 71, 28);
        getContentPane().add(Cuatro);
        Cuatro.setBounds(326, 177, 70, 28);

        jLabel4.setFont(new java.awt.Font("sansserif", 1, 18)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(0, 0, 0));
        jLabel4.setText(" .");
        getContentPane().add(jLabel4);
        jLabel4.setBounds(109, 177, 15, 24);

        jLabel6.setFont(new java.awt.Font("sansserif", 1, 18)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(0, 0, 0));
        jLabel6.setText(" .");
        getContentPane().add(jLabel6);
        jLabel6.setBounds(207, 177, 15, 24);

        jLabel8.setFont(new java.awt.Font("sansserif", 1, 18)); // NOI18N
        jLabel8.setForeground(new java.awt.Color(0, 0, 0));
        jLabel8.setText(" .");
        getContentPane().add(jLabel8);
        jLabel8.setBounds(305, 177, 15, 24);

        jLabel5.setIcon(new javax.swing.ImageIcon("C:\\Users\\rokon\\OneDrive\\Imágenes\\princ.JPG")); // NOI18N
        getContentPane().add(jLabel5);
        jLabel5.setBounds(0, 0, 480, 300);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ConfirmarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ConfirmarActionPerformed
        IP ip = new IP(Uno.getText(),Dos.getText(),Tres.getText(),Cuatro.getText());                     
        Limpiar();
        Cambiar_pantalla(ip,a);
    }//GEN-LAST:event_ConfirmarActionPerformed
     
    void Cambiar_pantalla(IP ip, Despliegue_info a) {
        a = new Despliegue_info(ip,this);
        a.setVisible(true);
    }
    
    void Limpiar() {
        this.setVisible(false);        
        Uno.setText(null);
        Dos.setText(null);
        Tres.setText(null);
        Cuatro.setText(null);
    }
    
    public static void main(String args[]) {
        
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Principal().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Confirmar;
    private javax.swing.JTextField Cuatro;
    private javax.swing.JTextField Dos;
    private javax.swing.JTextField Tres;
    private javax.swing.JTextField Uno;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    // End of variables declaration//GEN-END:variables
}