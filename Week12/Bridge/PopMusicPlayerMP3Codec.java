package LAB13.Bridge.start;

public class PopMusicPlayerMP3Codec implements MusicPlayer {
    public void play(String fileName) {
        System.out.println("Playing Pop music...");
        decode(fileName);
    }

    public void decode(String fileName) {
        System.out.println("Playing " + fileName + " using MP3 codec.");
    }
}
