#include "dye_color.hpp"

#include <array>

#if 1
namespace clr
{
    const std::array<const DyeColor, 73> dyes = {
        (DyeColor) {
            .name = "black",
            .primary_dye = "black",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.09930010267962124f,
                .g = 0.09930010267962124f,
                .b = 0.09930010267962124f,
                .a = 1.0f
            },
            .id = 7
        },
        (DyeColor) {
            .name = "black_black",
            .primary_dye = "black",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.020276249520463124f,
                .g = 0.020276249520463124f,
                .b = 0.020276249520463124f,
                .a = 1.0f
            },
            .id = 63
        },
        (DyeColor) {
            .name = "black_blue",
            .primary_dye = "black",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.12313846508195629f,
                .g = 0.1332085131842997f,
                .b = 0.06665646426952836f,
                .a = 1.0f
            },
            .id = 61
        },
        (DyeColor) {
            .name = "black_cyan",
            .primary_dye = "black",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.18116205135809363f,
                .g = 0.17335183323460518f,
                .b = 0.050591888267732414f,
                .a = 1.0f
            },
            .id = 60
        },
        (DyeColor) {
            .name = "black_green",
            .primary_dye = "black",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.10564902700492756f,
                .g = 0.07554944373121238f,
                .b = 0.05447224632874138f,
                .a = 1.0f
            },
            .id = 59
        },
        (DyeColor) {
            .name = "black_magenta",
            .primary_dye = "black",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.08818082449720015f,
                .g = 0.156181864191168f,
                .b = 0.05456225603304318f,
                .a = 1.0f
            },
            .id = 62
        },
        (DyeColor) {
            .name = "black_red",
            .primary_dye = "black",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.1483024886265502f,
                .g = 0.05292794564663585f,
                .b = 0.051809590035850575f,
                .a = 1.0f
            },
            .id = 57
        },
        (DyeColor) {
            .name = "black_white",
            .primary_dye = "black",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.17261062707677471f,
                .g = 0.17261062707677471f,
                .b = 0.17261062707677471f,
                .a = 1.0f
            },
            .id = 64
        },
        (DyeColor) {
            .name = "black_yellow",
            .primary_dye = "black",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.1332085131842997f,
                .g = 0.0339038718166269f,
                .b = 0.01774450798477175f,
                .a = 1.0f
            },
            .id = 58
        },
        (DyeColor) {
            .name = "blue",
            .primary_dye = "blue",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.41196066089083405f,
                .g = 0.45626345839647037f,
                .b = 0.159395994947778f,
                .a = 1.0f
            },
            .id = 5
        },
        (DyeColor) {
            .name = "blue_black",
            .primary_dye = "blue",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.17569666360033134f,
                .g = 0.1989439434439628f,
                .b = 0.051285783400457925f,
                .a = 1.0f
            },
            .id = 31
        },
        (DyeColor) {
            .name = "blue_blue",
            .primary_dye = "blue",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.24663031164589605f,
                .g = 0.27926316736019974f,
                .b = 0.07199128591213044f,
                .a = 1.0f
            },
            .id = 29
        },
        (DyeColor) {
            .name = "blue_cyan",
            .primary_dye = "blue",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.30732754624602016f,
                .g = 0.3370742966834595f,
                .b = 0.07336005471260763f,
                .a = 1.0f
            },
            .id = 28
        },
        (DyeColor) {
            .name = "blue_green",
            .primary_dye = "blue",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.3237604002063401f,
                .g = 0.3370742966834595f,
                .b = 0.12627622195052252f,
                .a = 1.0f
            },
            .id = 27
        },
        (DyeColor) {
            .name = "blue_magenta",
            .primary_dye = "blue",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.23053054224520328f,
                .g = 0.2903519068004137f,
                .b = 0.14528974942055195f,
                .a = 1.0f
            },
            .id = 30
        },
        (DyeColor) {
            .name = "blue_red",
            .primary_dye = "blue",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.3359173352861901f,
                .g = 0.38762286270293544f,
                .b = 0.20584682087074865f,
                .a = 1.0f
            },
            .id = 25
        },
        (DyeColor) {
            .name = "blue_white",
            .primary_dye = "blue",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.3647233135429514f,
                .g = 0.38762286270293544f,
                .b = 0.23077511999291608f,
                .a = 1.0f
            },
            .id = 32
        },
        (DyeColor) {
            .name = "blue_yellow",
            .primary_dye = "blue",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.3370742966834595f,
                .g = 0.3135272812947674f,
                .b = 0.13966584168909751f,
                .a = 1.0f
            },
            .id = 26
        },
        (DyeColor) {
            .name = "cyan",
            .primary_dye = "cyan",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.5310492251033824f,
                .g = 0.5153796773766689f,
                .b = 0.24229835602443497f,
                .a = 1.0f
            },
            .id = 4
        },
        (DyeColor) {
            .name = "cyan_black",
            .primary_dye = "cyan",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.301676572952874f,
                .g = 0.29395353911720806f,
                .b = 0.1555433216884527f,
                .a = 1.0f
            },
            .id = 39
        },
        (DyeColor) {
            .name = "cyan_blue",
            .primary_dye = "cyan",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.4937313857542173f,
                .g = 0.5155962896487515f,
                .b = 0.19985690979266088f,
                .a = 1.0f
            },
            .id = 37
        },
        (DyeColor) {
            .name = "cyan_cyan",
            .primary_dye = "cyan",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.42807474628889924f,
                .g = 0.40631183237133184f,
                .b = 0.0851628781154875f,
                .a = 1.0f
            },
            .id = 36
        },
        (DyeColor) {
            .name = "cyan_green",
            .primary_dye = "cyan",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.3493507797183064f,
                .g = 0.31215583021293397f,
                .b = 0.05456225603304318f,
                .a = 1.0f
            },
            .id = 35
        },
        (DyeColor) {
            .name = "cyan_magenta",
            .primary_dye = "cyan",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.4741998979455138f,
                .g = 0.4854354541103905f,
                .b = 0.30535042843080235f,
                .a = 1.0f
            },
            .id = 38
        },
        (DyeColor) {
            .name = "cyan_red",
            .primary_dye = "cyan",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.3554407396168024f,
                .g = 0.37462429853886575f,
                .b = 0.2971183424161177f,
                .a = 1.0f
            },
            .id = 33
        },
        (DyeColor) {
            .name = "cyan_white",
            .primary_dye = "cyan",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.5789061001564332f,
                .g = 0.5680553246356429f,
                .b = 0.36414568447193324f,
                .a = 1.0f
            },
            .id = 40
        },
        (DyeColor) {
            .name = "cyan_yellow",
            .primary_dye = "cyan",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.45626345839647037f,
                .g = 0.4254926195508575f,
                .b = 0.159395994947778f,
                .a = 1.0f
            },
            .id = 34
        },
        (DyeColor) {
            .name = "green",
            .primary_dye = "green",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.301676572952874f,
                .g = 0.19453952761854526f,
                .b = 0.1291401224281061f,
                .a = 1.0f
            },
            .id = 3
        },
        (DyeColor) {
            .name = "green_black",
            .primary_dye = "green",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.1406450606868577f,
                .g = 0.057639320029438536f,
                .b = 0.019781033095609888f,
                .a = 1.0f
            },
            .id = 47
        },
        (DyeColor) {
            .name = "green_blue",
            .primary_dye = "green",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.2903519068004137f,
                .g = 0.24750955284664045f,
                .b = 0.13667624847447502f,
                .a = 1.0f
            },
            .id = 45
        },
        (DyeColor) {
            .name = "green_cyan",
            .primary_dye = "green",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.23866811073755134f,
                .b = 0.08724301538940077f,
                .a = 1.0f
            },
            .id = 44
        },
        (DyeColor) {
            .name = "green_green",
            .primary_dye = "green",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.1989439434439628f,
                .g = 0.08855496345357403f,
                .b = 0.03433983883098881f,
                .a = 1.0f
            },
            .id = 43
        },
        (DyeColor) {
            .name = "green_magenta",
            .primary_dye = "green",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.2903519068004137f,
                .g = 0.23819311399556628f,
                .b = 0.2246894582423061f,
                .a = 1.0f
            },
            .id = 46
        },
        (DyeColor) {
            .name = "green_red",
            .primary_dye = "green",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.27926316736019974f,
                .g = 0.036231181326328236f,
                .b = 0.008096170580675738f,
                .a = 1.0f
            },
            .id = 41
        },
        (DyeColor) {
            .name = "green_white",
            .primary_dye = "green",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.37462429853886575f,
                .g = 0.26789321364490076f,
                .b = 0.19315489833890537f,
                .a = 1.0f
            },
            .id = 48
        },
        (DyeColor) {
            .name = "green_yellow",
            .primary_dye = "green",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.301676572952874f,
                .g = 0.14237073592931176f,
                .b = 0.07776924046854188f,
                .a = 1.0f
            },
            .id = 42
        },
        (DyeColor) {
            .name = "magenta",
            .primary_dye = "magenta",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.28972936088456697f,
                .g = 0.42807474628889924f,
                .b = 0.2142051461171666f,
                .a = 1.0f
            },
            .id = 6
        },
        (DyeColor) {
            .name = "magenta_black",
            .primary_dye = "magenta",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.09896398259176345f,
                .g = 0.217637640824031f,
                .b = 0.04736614270344993f,
                .a = 1.0f
            },
            .id = 23
        },
        (DyeColor) {
            .name = "magenta_blue",
            .primary_dye = "magenta",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.14093827860784724f,
                .g = 0.2273287623030469f,
                .b = 0.08226282056995202f,
                .a = 1.0f
            },
            .id = 21
        },
        (DyeColor) {
            .name = "magenta_cyan",
            .primary_dye = "magenta",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.4039498062599399f,
                .g = 0.45626345839647037f,
                .b = 0.3274253351803555f,
                .a = 1.0f
            },
            .id = 20
        },
        (DyeColor) {
            .name = "magenta_green",
            .primary_dye = "magenta",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.27039521783733844f,
                .g = 0.3493507797183064f,
                .b = 0.23805436338900945f,
                .a = 1.0f
            },
            .id = 19
        },
        (DyeColor) {
            .name = "magenta_magenta",
            .primary_dye = "magenta",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.28972936088456697f,
                .g = 0.42807474628889924f,
                .b = 0.2142051461171666f,
                .a = 1.0f
            },
            .id = 22
        },
        (DyeColor) {
            .name = "magenta_red",
            .primary_dye = "magenta",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.1889413255174646f,
                .g = 0.2903519068004137f,
                .b = 0.12429231883808517f,
                .a = 1.0f
            },
            .id = 17
        },
        (DyeColor) {
            .name = "magenta_white",
            .primary_dye = "magenta",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.34924325087176167f,
                .g = 0.45626345839647037f,
                .b = 0.287000550369771f,
                .a = 1.0f
            },
            .id = 24
        },
        (DyeColor) {
            .name = "magenta_yellow",
            .primary_dye = "magenta",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.32289068042376423f,
                .g = 0.5155962896487515f,
                .b = 0.281902992720853f,
                .a = 1.0f
            },
            .id = 18
        },
        (DyeColor) {
            .name = "none",
            .primary_dye = "none",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.217637640824031f,
                .g = 0.217637640824031f,
                .b = 0.217637640824031f,
                .a = 1.0f
            },
            .id = 0
        },
        (DyeColor) {
            .name = "red",
            .primary_dye = "red",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.2903519068004137f,
                .g = 0.05809439149847759f,
                .b = 0.05514929562501207f,
                .a = 1.0f
            },
            .id = 1
        },
        (DyeColor) {
            .name = "red_black",
            .primary_dye = "red",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.2081763434679077f,
                .g = 0.038754822609287115f,
                .b = 0.03771365342687323f,
                .a = 1.0f
            },
            .id = 15
        },
        (DyeColor) {
            .name = "red_blue",
            .primary_dye = "red",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.20968592762219468f,
                .g = 0.3250369625210763f,
                .b = 0.1483024886265502f,
                .a = 1.0f
            },
            .id = 13
        },
        (DyeColor) {
            .name = "red_cyan",
            .primary_dye = "red",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.18966255013919886f,
                .b = 0.18772389363446887f,
                .a = 1.0f
            },
            .id = 12
        },
        (DyeColor) {
            .name = "red_green",
            .primary_dye = "red",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.2474041117391939f,
                .g = 0.04459347401148373f,
                .b = 0.029439526843727103f,
                .a = 1.0f
            },
            .id = 11
        },
        (DyeColor) {
            .name = "red_magenta",
            .primary_dye = "red",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.1281436355284373f,
                .g = 0.3250369625210763f,
                .b = 0.08724301538940074f,
                .a = 1.0f
            },
            .id = 14
        },
        (DyeColor) {
            .name = "red_red",
            .primary_dye = "red",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.25779012174303145f,
                .g = 0.023713139771468408f,
                .b = 0.02101823405337801f,
                .a = 1.0f
            },
            .id = 9
        },
        (DyeColor) {
            .name = "red_white",
            .primary_dye = "red",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.4143473503120746f,
                .g = 0.17834729111711006f,
                .b = 0.17737163686031893f,
                .a = 1.0f
            },
            .id = 16
        },
        (DyeColor) {
            .name = "red_yellow",
            .primary_dye = "red",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.42807474628889924f,
                .g = 0.09908226830206707f,
                .b = 0.07389025039265812f,
                .a = 1.0f
            },
            .id = 10
        },
        (DyeColor) {
            .name = "white",
            .primary_dye = "white",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.38762286270293544f,
                .g = 0.38762286270293544f,
                .b = 0.38762286270293544f,
                .a = 1.0f
            },
            .id = 8
        },
        (DyeColor) {
            .name = "white_black",
            .primary_dye = "white",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.26840952091331366f,
                .b = 0.26840952091331366f,
                .a = 1.0f
            },
            .id = 71
        },
        (DyeColor) {
            .name = "white_blue",
            .primary_dye = "white",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.5163051993019451f,
                .g = 0.5467513990701884f,
                .b = 0.34391961390042436f,
                .a = 1.0f
            },
            .id = 69
        },
        (DyeColor) {
            .name = "white_cyan",
            .primary_dye = "white",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.5467513990701884f,
                .g = 0.5418838603031999f,
                .b = 0.44430476010449066f,
                .a = 1.0f
            },
            .id = 68
        },
        (DyeColor) {
            .name = "white_green",
            .primary_dye = "white",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.47072619560382467f,
                .g = 0.372154334861437f,
                .b = 0.29609795552457346f,
                .a = 1.0f
            },
            .id = 67
        },
        (DyeColor) {
            .name = "white_magenta",
            .primary_dye = "white",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.4125871201740721f,
                .g = 0.5155962896487515f,
                .b = 0.35133726221260553f,
                .a = 1.0f
            },
            .id = 70
        },
        (DyeColor) {
            .name = "white_red",
            .primary_dye = "white",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.5155962896487515f,
                .g = 0.24386319766077602f,
                .b = 0.24270467989380443f,
                .a = 1.0f
            },
            .id = 65
        },
        (DyeColor) {
            .name = "white_white",
            .primary_dye = "white",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.6993935721642928f,
                .g = 0.6993935721642928f,
                .b = 0.6993935721642928f,
                .a = 1.0f
            },
            .id = 72
        },
        (DyeColor) {
            .name = "white_yellow",
            .primary_dye = "white",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.7176234019070601f,
                .g = 0.4130175602187818f,
                .b = 0.34835984198499703f,
                .a = 1.0f
            },
            .id = 66
        },
        (DyeColor) {
            .name = "yellow",
            .primary_dye = "yellow",
            .secondary_dye = "",
            .color = (Color) {
                .r = 0.5003919244808795f,
                .g = 0.1890708408967579f,
                .b = 0.12899609513115573f,
                .a = 1.0f
            },
            .id = 2
        },
        (DyeColor) {
            .name = "yellow_black",
            .primary_dye = "yellow",
            .secondary_dye = "black",
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.08524549158942918f,
                .b = 0.05098156984927748f,
                .a = 1.0f
            },
            .id = 55
        },
        (DyeColor) {
            .name = "yellow_blue",
            .primary_dye = "yellow",
            .secondary_dye = "blue",
            .color = (Color) {
                .r = 0.37462429853886575f,
                .g = 0.20316568796776116f,
                .b = 0.09657444352823195f,
                .a = 1.0f
            },
            .id = 53
        },
        (DyeColor) {
            .name = "yellow_cyan",
            .primary_dye = "yellow",
            .secondary_dye = "cyan",
            .color = (Color) {
                .r = 0.5155962896487515f,
                .g = 0.31305390850169657f,
                .b = 0.23524774625152764f,
                .a = 1.0f
            },
            .id = 52
        },
        (DyeColor) {
            .name = "yellow_green",
            .primary_dye = "yellow",
            .secondary_dye = "green",
            .color = (Color) {
                .r = 0.4143473503120746f,
                .g = 0.18249722540061492f,
                .b = 0.10681465388085219f,
                .a = 1.0f
            },
            .id = 51
        },
        (DyeColor) {
            .name = "yellow_magenta",
            .primary_dye = "yellow",
            .secondary_dye = "magenta",
            .color = (Color) {
                .r = 0.47072619560382467f,
                .g = 0.2530431692205921f,
                .b = 0.2285071845245992f,
                .a = 1.0f
            },
            .id = 54
        },
        (DyeColor) {
            .name = "yellow_red",
            .primary_dye = "yellow",
            .secondary_dye = "red",
            .color = (Color) {
                .r = 0.6120655998656237f,
                .g = 0.11674770202714885f,
                .b = 0.07711522087515978f,
                .a = 1.0f
            },
            .id = 49
        },
        (DyeColor) {
            .name = "yellow_white",
            .primary_dye = "yellow",
            .secondary_dye = "white",
            .color = (Color) {
                .r = 0.8126266541980146f,
                .g = 0.3044874311800493f,
                .b = 0.20948712411733847f,
                .a = 1.0f
            },
            .id = 56
        },
        (DyeColor) {
            .name = "yellow_yellow",
            .primary_dye = "yellow",
            .secondary_dye = "yellow",
            .color = (Color) {
                .r = 0.5003919244808795f,
                .g = 0.041007936471073606f,
                .b = 0.004715296793172928f,
                .a = 1.0f
            },
            .id = 50
        }
    };
}
#endif