package LAB13.Bridge.start;

public class PopMusicPlayerWAVCodec implements MusicPlayer {
    public void play(String fileName) {
        System.out.println("Playing Pop music...");
        decode(fileName);
    }

    public void decode(String fileName) {
        System.out.println("Playing " + fileName + " using WAV codec.");
    }
}
