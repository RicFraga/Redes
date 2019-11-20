package Clases;

public class IP {
    public short arr[];
    //public short mr[];
    
    public IP(String ip1, String ip2, String ip3, String ip4) {
        this.arr = new short[4];
        //this.mr = new short[4];
        this.arr[0] = (short)Integer.parseInt(ip1);
        this.arr[1] = (short)Integer.parseInt(ip2);
        this.arr[2] = (short)Integer.parseInt(ip3);
        this.arr[3] = (short)Integer.parseInt(ip4);    
        
        /*this.mr[0] = 0;
        this.mr[1] = 0;
        this.mr[2] = 0;
        this.mr[3] = 0;*/
                
    }
    
    public String imprimirIP() {
        return this.arr[0] + " . " + this.arr[1] + " . " + this.arr[2] + " . " + this.arr[3];
    }
            
}
