package LAB13.Bridge.start;

public class JazzMusicPlayerMP3Codec implements MusicPlayer {
    public void play(String fileName) {
        System.out.println("Playing Jazz music...");
        decode(fileName);
    }

    public void decode(String fileName) {
        System.out.println("Playing " + fileName + " using MP3 codec.");
    }
}
