package Vistas;
import Clases.IP;

public class Despliegue_info extends javax.swing.JFrame {
    Principal b;
    
    public Despliegue_info(IP ip, Principal prin) {
        initComponents();
        setLocationRelativeTo(null);
        setSize(430,355);
        setTitle("Detalles de la IP");
        this.b = prin;
        IPtext.setText("IP:     " + ip.imprimirIP());
        
        /* Aplicamos una operacion & al primer MSB de la ip para obtener un
        valor decimal, si este valor, al operarlo con los límites de los
        valores en las clasificaciones de las redes es menor al límite, la
        ip pertenece a esa clase*/
        
        /* PARA CLASE A
        -> Para clase A el MSB debe ser 0 siempre, por lo cual no puede
        tomar el valor de 128, entonces, si el valor decimal despues de 
        la operacion & es menor a 127, la ip pertenece a esta clase*/
        if((ip.arr[0] & 128) < 127) {
            RedA(ip);                                    
        }
        
        /* PARA CLASE B
        -> Para clase B el MSB debe ser 1 y el siguiente 0, por lo cual no puede
        tomar el valor de 192, entonces, si el valor decimal despues de 
        la operacion & es menor a 192 y mayor a 127, la ip pertenece a esta clase*/
        else if((ip.arr[0]&192) < 192) {
            RedB(ip);                        
        }
        
        /* PARA CLASE C
        -> Para clase C el MSB debe ser 0 siempre, por lo cual no puede
        tomar el valor de 128, entonces, si el valor decimal despues de 
        la operacion & es menor a 127, la ip pertenece a esta clase*/
        else if((ip.arr[0]&224) < 224) {
            RedC(ip);            
        }
        
        /* PARA LA CLASE D
        -> Para clase D los primero 3 bits deben ser 1, por lo cual el valor
        no puede ser 240, entonces si el valor decimal despues de la operacion
        & es menor a 240, la ip pertenece a esta clase*/        
        else if((ip.arr[0]&240) < 240) {
            RedD(ip);            
        }
        
        /* PARA LA CLASE E
        -> Para clase E los primero 4 bits deben ser 1, por lo cual el valor
        no puede ser 256, entonces si el valor decimal despues de la operacion
        & es menor a 256, la ip pertenece a esta clase*/        
        else {
            RedE(ip);            
        }             
    }
    
    void RedA(IP ip) {
        Clase.setText("A");            
            
            //Comparamos la porcion de host para saber el tipo
            if(((ip.arr[1]&255)>254) && ((ip.arr[2] & 255)>254) && (ip.arr[3]&255)>254) {
                Tipo.setText("Broadcast");                
            }else if(((ip.arr[1]&255)<1) && ((ip.arr[2]&255)<1) && (ip.arr[3]&255)<1) {
                Tipo.setText("Red");
            }else{
                Tipo.setText("Host");
            }
            
            // Construimos la IP de Red
            IPRed.setText((ip.arr[0] & 255) + ".0.0.0");
            
            // Construimos el rango de red
            RangoHost.setText("R.H.H.H");
            
            // Construimos la IP de Broadcast
            IPBr.setText((ip.arr[0])+"."+255+"."+255+"."+255);
    }
    
    void RedB(IP ip) {
        Clase.setText("B");
            
            //Comparamos la porcion de host para saber el tipo
            if(((ip.arr[2] & 255) > 254) && (ip.arr[3] & 255) > 254) {
                Tipo.setText("Broadcast");                
            }else if(((ip.arr[2] & 255) < 1) && (ip.arr[3] & 255) < 1) {
                Tipo.setText("Red");
            }else{
                Tipo.setText("Host");
            }
            
            // Construimos la IP de Red
            IPRed.setText((ip.arr[0] & 255) +"."+ ((ip.arr[1] & 255)) + ".0.0");
            
            // Construimos el rango de red
            RangoHost.setText("R.R.H.H");
            
            // Construimos la IP de Broadcast
            IPBr.setText((ip.arr[0])+"."+ip.arr[1]+"."+255+"."+255);
    }
    
    void RedC(IP ip) {
        Clase.setText("C");
            
            //Comparamos la porcion de host para saber el tipo
            if((ip.arr[3] & 255) > 254) {
                Tipo.setText("Broadcast");                
            }else if((ip.arr[3] & 255) < 1) {
                Tipo.setText("Red");
            }else{
                Tipo.setText("Host");
            }
            
            // Construimos la IP de Red
            IPRed.setText((ip.arr[0] & 255) +"."+ (ip.arr[1] & 255) + "." + (ip.arr[3] & 255)+".0");
            
            // Construimos el rango de red
            RangoHost.setText("R.R.R.H");
            
            // Construimos la IP de Broadcast
            IPBr.setText((ip.arr[0])+".255.255.255");
    }
    
    void RedD(IP ip) {
        Clase.setText("D");                                    
            Tipo.setText("--------");
            RangoHost.setText("--------");
            
            // Construimos la IP de Red
            IPRed.setText((ip.arr[0] & 255) +"."+ (ip.arr[1] & 255) + "." + (ip.arr[2] & 255)+".0");                        
            
            // Construimos la IP de Broadcast
            IPBr.setText((ip.arr[0])+".255.255.255");
    }
    
    void RedE(IP ip) {
        Clase.setText("E");            
            Tipo.setText("--------");
            RangoHost.setText("--------");
            
            // Construimos la IP de Red
            IPRed.setText((ip.arr[0] & 255) +"."+ (ip.arr[1] & 255) + "." + (ip.arr[2] & 255)+ "." + (ip.arr[3]&255));                        
            
            // Construimos la IP de Broadcast
            IPBr.setText("255.255.255.255");
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        IPtext = new javax.swing.JLabel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        Clase = new javax.swing.JLabel();
        Tipo = new javax.swing.JLabel();
        IPRed = new javax.swing.JLabel();
        RangoHost = new javax.swing.JLabel();
        IPBr = new javax.swing.JLabel();
        Regresar = new javax.swing.JButton();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(204, 0, 153));
        getContentPane().setLayout(null);

        IPtext.setFont(new java.awt.Font("Arial", 1, 20)); // NOI18N
        IPtext.setText("jLabel1");
        getContentPane().add(IPtext);
        IPtext.setBounds(50, 32, 310, 24);

        jLabel1.setFont(new java.awt.Font("sansserif", 1, 14)); // NOI18N
        jLabel1.setText("Clase: ");
        jLabel1.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                jLabel1FocusGained(evt);
            }
        });
        getContentPane().add(jLabel1);
        jLabel1.setBounds(40, 91, 80, 19);

        jLabel2.setFont(new java.awt.Font("sansserif", 1, 14)); // NOI18N
        jLabel2.setText("Tipo: ");
        getContentPane().add(jLabel2);
        jLabel2.setBounds(40, 128, 80, 19);

        jLabel3.setFont(new java.awt.Font("sansserif", 1, 14)); // NOI18N
        jLabel3.setText("IP Red:");
        getContentPane().add(jLabel3);
        jLabel3.setBounds(40, 165, 90, 19);

        jLabel4.setFont(new java.awt.Font("sansserif", 1, 14)); // NOI18N
        jLabel4.setText("Rango Host:");
        getContentPane().add(jLabel4);
        jLabel4.setBounds(40, 205, 120, 19);

        jLabel5.setFont(new java.awt.Font("sansserif", 1, 14)); // NOI18N
        jLabel5.setText("IP Broadcast:");
        getContentPane().add(jLabel5);
        jLabel5.setBounds(40, 242, 130, 19);

        Clase.setText("jLabel6");
        getContentPane().add(Clase);
        Clase.setBounds(245, 93, 130, 16);

        Tipo.setText("jLabel6");
        getContentPane().add(Tipo);
        Tipo.setBounds(245, 130, 120, 16);

        IPRed.setText("jLabel6");
        getContentPane().add(IPRed);
        IPRed.setBounds(245, 167, 120, 16);

        RangoHost.setText("jLabel6");
        getContentPane().add(RangoHost);
        RangoHost.setBounds(245, 202, 130, 22);

        IPBr.setText("jLabel6");
        getContentPane().add(IPBr);
        IPBr.setBounds(245, 244, 110, 16);

        Regresar.setText("Ingresar otra IP");
        Regresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                RegresarActionPerformed(evt);
            }
        });
        getContentPane().add(Regresar);
        Regresar.setBounds(230, 280, 150, 28);

        jLabel6.setIcon(new javax.swing.ImageIcon("C:\\Users\\rokon\\OneDrive\\Imágenes\\desp.jpg")); // NOI18N
        getContentPane().add(jLabel6);
        jLabel6.setBounds(0, 0, 420, 320);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jLabel1FocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_jLabel1FocusGained
        
    }//GEN-LAST:event_jLabel1FocusGained

    private void RegresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_RegresarActionPerformed
        this.setVisible(false);
        b.setVisible(true);                
    }//GEN-LAST:event_RegresarActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel Clase;
    private javax.swing.JLabel IPBr;
    private javax.swing.JLabel IPRed;
    private javax.swing.JLabel IPtext;
    private javax.swing.JLabel RangoHost;
    private javax.swing.JButton Regresar;
    private javax.swing.JLabel Tipo;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    // End of variables declaration//GEN-END:variables
}