package LAB13.Bridge.start;

// Client
public class MusicStreamingApp {
    public static void main(String[] args) {

        MusicPlayer popMusicPlayer1 = new PopMusicPlayerMP3Codec();
        MusicPlayer jazzMusicPlayer = new JazzMusicPlayerMP3Codec();
        MusicPlayer popMusicPlayer2 = new PopMusicPlayerWAVCodec();

        popMusicPlayer1.play("pop_song_1.mp3");
        jazzMusicPlayer.play("jazz_song.mp3");
        popMusicPlayer2.play("pop_song_2.wav");
    }
}