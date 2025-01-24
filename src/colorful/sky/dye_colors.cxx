#include "dye_colors.hpp"

#include <misc/Logger.h>

#define CLR_BASE_DYES_COUNT 9

namespace clr
{
    static const std::array<const DyeColor, CLR_DYE_COLOR_COUNT> _dyes = {
        (DyeColor) {
            .name = "none",
            .primary_dye = CLR_DYE_COLOR_NONE,
            .secondary_dye = CLR_DYE_COLOR_NONE,
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
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.2903519068004137f,
                .g = 0.0646838952212678f,
                .b = 0.05514929562501207f,
                .a = 1.0f
            },
            .id = 1
        },
        (DyeColor) {
            .name = "yellow",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.5003919244808795f,
                .g = 0.3609327388629735f,
                .b = 0.12899609513115573f,
                .a = 1.0f
            },
            .id = 2
        },
        (DyeColor) {
            .name = "green",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.22924210260386413f,
                .g = 0.301676572952874f,
                .b = 0.1291401224281061f,
                .a = 1.0f
            },
            .id = 3
        },
        (DyeColor) {
            .name = "cyan",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.24229835602443497f,
                .g = 0.5310492251033824f,
                .b = 0.5310492251033824f,
                .a = 1.0f
            },
            .id = 4
        },
        (DyeColor) {
            .name = "blue",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.159395994947778f,
                .g = 0.28208681706330246f,
                .b = 0.45626345839647037f,
                .a = 1.0f
            },
            .id = 5
        },
        (DyeColor) {
            .name = "magenta",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.42807474628889924f,
                .g = 0.2142051461171666f,
                .b = 0.41964460855280894f,
                .a = 1.0f
            },
            .id = 6
        },
        (DyeColor) {
            .name = "black",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.09930010267962124f,
                .g = 0.09930010267962124f,
                .b = 0.09930010267962124f,
                .a = 1.0f
            },
            .id = 7
        },
        (DyeColor) {
            .name = "white",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_NONE,
            .color = (Color) {
                .r = 0.38762286270293544f,
                .g = 0.38762286270293544f,
                .b = 0.38762286270293544f,
                .a = 1.0f
            },
            .id = 8
        },
        (DyeColor) {
            .name = "red_red",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.25779012174303145f,
                .g = 0.03008652897362178f,
                .b = 0.02101823405337801f,
                .a = 1.0f
            },
            .id = 9
        },
        (DyeColor) {
            .name = "red_yellow",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.42807474628889924f,
                .g = 0.1668690230673243f,
                .b = 0.07389025039265812f,
                .a = 1.0f
            },
            .id = 10
        },
        (DyeColor) {
            .name = "red_green",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.2474041117391939f,
                .g = 0.08890335066613572f,
                .b = 0.029439526843727103f,
                .a = 1.0f
            },
            .id = 11
        },
        (DyeColor) {
            .name = "red_cyan",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.19385095510794523f,
                .b = 0.18772389363446887f,
                .a = 1.0f
            },
            .id = 12
        },
        (DyeColor) {
            .name = "red_blue",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.3250369625210763f,
                .g = 0.1483024886265502f,
                .b = 0.31792902556399927f,
                .a = 1.0f
            },
            .id = 13
        },
        (DyeColor) {
            .name = "red_magenta",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.3250369625210763f,
                .g = 0.08724301538940074f,
                .b = 0.17387897052674303f,
                .a = 1.0f
            },
            .id = 14
        },
        (DyeColor) {
            .name = "red_black",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.2081763434679077f,
                .g = 0.04103673016606597f,
                .b = 0.03771365342687323f,
                .a = 1.0f
            },
            .id = 15
        },
        (DyeColor) {
            .name = "red_white",
            .primary_dye = CLR_DYE_COLOR_RED,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.4143473503120746f,
                .g = 0.18044657707898504f,
                .b = 0.17737163686031893f,
                .a = 1.0f
            },
            .id = 16
        },
        (DyeColor) {
            .name = "magenta_red",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.26703718283051747f,
                .g = 0.12429231883808517f,
                .b = 0.2903519068004137f,
                .a = 1.0f
            },
            .id = 17
        },
        (DyeColor) {
            .name = "magenta_yellow",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.5155962896487515f,
                .g = 0.281902992720853f,
                .b = 0.355028457845608f,
                .a = 1.0f
            },
            .id = 18
        },
        (DyeColor) {
            .name = "magenta_green",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.3493507797183064f,
                .g = 0.23805436338900945f,
                .b = 0.31351837778790403f,
                .a = 1.0f
            },
            .id = 19
        },
        (DyeColor) {
            .name = "magenta_cyan",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.3698760671006433f,
                .g = 0.3274253351803555f,
                .b = 0.45626345839647037f,
                .a = 1.0f
            },
            .id = 20
        },
        (DyeColor) {
            .name = "magenta_blue",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.1919546150739989f,
                .g = 0.08226282056995202f,
                .b = 0.2273287623030469f,
                .a = 1.0f
            },
            .id = 21
        },
        (DyeColor) {
            .name = "magenta_magenta",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.42807474628889924f,
                .g = 0.2142051461171666f,
                .b = 0.41964460855280894f,
                .a = 1.0f
            },
            .id = 22
        },
        (DyeColor) {
            .name = "magenta_black",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.217637640824031f,
                .g = 0.04736614270344993f,
                .b = 0.20973730549758715f,
                .a = 1.0f
            },
            .id = 23
        },
        (DyeColor) {
            .name = "magenta_white",
            .primary_dye = CLR_DYE_COLOR_MAGENTA,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.45626345839647037f,
                .g = 0.287000550369771f,
                .b = 0.4499303349592195f,
                .a = 1.0f
            },
            .id = 24
        },
        (DyeColor) {
            .name = "blue_red",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.20584682087074865f,
                .g = 0.2160448227669093f,
                .b = 0.38762286270293544f,
                .a = 1.0f
            },
            .id = 25
        },
        (DyeColor) {
            .name = "blue_yellow",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.13966584168909751f,
                .g = 0.3370742966834595f,
                .b = 0.29762925395718176f,
                .a = 1.0f
            },
            .id = 26
        },
        (DyeColor) {
            .name = "blue_green",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.12627622195052252f,
                .g = 0.26213699503131094f,
                .b = 0.3370742966834595f,
                .a = 1.0f
            },
            .id = 27
        },
        (DyeColor) {
            .name = "blue_cyan",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.07336005471260763f,
                .g = 0.20631158159884486f,
                .b = 0.3370742966834595f,
                .a = 1.0f
            },
            .id = 28
        },
        (DyeColor) {
            .name = "blue_blue",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.07199128591213044f,
                .g = 0.15372073812656648f,
                .b = 0.27926316736019974f,
                .a = 1.0f
            },
            .id = 29
        },
        (DyeColor) {
            .name = "blue_magenta",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.18313466642880613f,
                .g = 0.14528974942055195f,
                .b = 0.2903519068004137f,
                .a = 1.0f
            },
            .id = 30
        },
        (DyeColor) {
            .name = "blue_black",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.051285783400457925f,
                .g = 0.10950892708514894f,
                .b = 0.1989439434439628f,
                .a = 1.0f
            },
            .id = 31
        },
        (DyeColor) {
            .name = "blue_white",
            .primary_dye = CLR_DYE_COLOR_BLUE,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.23077511999291608f,
                .g = 0.2958997692961867f,
                .b = 0.38762286270293544f,
                .a = 1.0f
            },
            .id = 32
        },
        (DyeColor) {
            .name = "cyan_red",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.2971183424161177f,
                .g = 0.305657678201019f,
                .b = 0.37462429853886575f,
                .a = 1.0f
            },
            .id = 33
        },
        (DyeColor) {
            .name = "cyan_yellow",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.159395994947778f,
                .g = 0.45626345839647037f,
                .b = 0.4129427561661046f,
                .a = 1.0f
            },
            .id = 34
        },
        (DyeColor) {
            .name = "cyan_green",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.05456225603304318f,
                .g = 0.3493507797183064f,
                .b = 0.29358918515492677f,
                .a = 1.0f
            },
            .id = 35
        },
        (DyeColor) {
            .name = "cyan_cyan",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.0851628781154875f,
                .g = 0.42807474628889924f,
                .b = 0.42807474628889924f,
                .a = 1.0f
            },
            .id = 36
        },
        (DyeColor) {
            .name = "cyan_blue",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.19985690979266088f,
                .g = 0.3981738778951052f,
                .b = 0.5155962896487515f,
                .a = 1.0f
            },
            .id = 37
        },
        (DyeColor) {
            .name = "cyan_magenta",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.30535042843080235f,
                .g = 0.4234901850205335f,
                .b = 0.4854354541103905f,
                .a = 1.0f
            },
            .id = 38
        },
        (DyeColor) {
            .name = "cyan_black",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.1555433216884527f,
                .g = 0.301676572952874f,
                .b = 0.301676572952874f,
                .a = 1.0f
            },
            .id = 39
        },
        (DyeColor) {
            .name = "cyan_white",
            .primary_dye = CLR_DYE_COLOR_CYAN,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.36414568447193324f,
                .g = 0.5789061001564332f,
                .b = 0.5789061001564332f,
                .a = 1.0f
            },
            .id = 40
        },
        (DyeColor) {
            .name = "green_red",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.27926316736019974f,
                .g = 0.1772574580241771f,
                .b = 0.008096170580675738f,
                .a = 1.0f
            },
            .id = 41
        },
        (DyeColor) {
            .name = "green_yellow",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.2531222471586278f,
                .g = 0.301676572952874f,
                .b = 0.07776924046854188f,
                .a = 1.0f
            },
            .id = 42
        },
        (DyeColor) {
            .name = "green_green",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.11816855767975537f,
                .g = 0.1989439434439628f,
                .b = 0.03433983883098881f,
                .a = 1.0f
            },
            .id = 43
        },
        (DyeColor) {
            .name = "green_cyan",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.08724301538940077f,
                .g = 0.26840952091331366f,
                .b = 0.2094246042206616f,
                .a = 1.0f
            },
            .id = 44
        },
        (DyeColor) {
            .name = "green_blue",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.13667624847447502f,
                .g = 0.2903519068004137f,
                .b = 0.18822338030119024f,
                .a = 1.0f
            },
            .id = 45
        },
        (DyeColor) {
            .name = "green_magenta",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.2903519068004137f,
                .g = 0.2685652230612296f,
                .b = 0.2246894582423061f,
                .a = 1.0f
            },
            .id = 46
        },
        (DyeColor) {
            .name = "green_black",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.08226469814368152f,
                .g = 0.1406450606868577f,
                .b = 0.019781033095609888f,
                .a = 1.0f
            },
            .id = 47
        },
        (DyeColor) {
            .name = "green_white",
            .primary_dye = CLR_DYE_COLOR_GREEN,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.2879962911409457f,
                .g = 0.37462429853886575f,
                .b = 0.19315489833890537f,
                .a = 1.0f
            },
            .id = 48
        },
        (DyeColor) {
            .name = "yellow_red",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.6120655998656237f,
                .g = 0.23259164845881738f,
                .b = 0.07711522087515978f,
                .a = 1.0f
            },
            .id = 49
        },
        (DyeColor) {
            .name = "yellow_yellow",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.5003919244808795f,
                .g = 0.2662526760527125f,
                .b = 0.004715296793172928f,
                .a = 1.0f
            },
            .id = 50
        },
        (DyeColor) {
            .name = "yellow_green",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.40739082304352f,
                .g = 0.4143473503120746f,
                .b = 0.10681465388085219f,
                .a = 1.0f
            },
            .id = 51
        },
        (DyeColor) {
            .name = "yellow_cyan",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.5099417394629325f,
                .g = 0.5155962896487515f,
                .b = 0.23524774625152764f,
                .a = 1.0f
            },
            .id = 52
        },
        (DyeColor) {
            .name = "yellow_blue",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.21544757377829016f,
                .g = 0.37462429853886575f,
                .b = 0.09657444352823195f,
                .a = 1.0f
            },
            .id = 53
        },
        (DyeColor) {
            .name = "yellow_magenta",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.47072619560382467f,
                .g = 0.31021694495424335f,
                .b = 0.2285071845245992f,
                .a = 1.0f
            },
            .id = 54
        },
        (DyeColor) {
            .name = "yellow_black",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.19196057653209422f,
                .b = 0.05098156984927748f,
                .a = 1.0f
            },
            .id = 55
        },
        (DyeColor) {
            .name = "yellow_white",
            .primary_dye = CLR_DYE_COLOR_YELLOW,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.8126266541980146f,
                .g = 0.5747397521106479f,
                .b = 0.20948712411733847f,
                .a = 1.0f
            },
            .id = 56
        },
        (DyeColor) {
            .name = "black_red",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.1483024886265502f,
                .g = 0.055366915150082595f,
                .b = 0.051809590035850575f,
                .a = 1.0f
            },
            .id = 57
        },
        (DyeColor) {
            .name = "black_yellow",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.1332085131842997f,
                .g = 0.08841048726598472f,
                .b = 0.01774450798477175f,
                .a = 1.0f
            },
            .id = 58
        },
        (DyeColor) {
            .name = "black_green",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.08121877854357097f,
                .g = 0.10564902700492756f,
                .b = 0.05447224632874138f,
                .a = 1.0f
            },
            .id = 59
        },
        (DyeColor) {
            .name = "black_cyan",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.050591888267732414f,
                .g = 0.18116205135809363f,
                .b = 0.18116205135809363f,
                .a = 1.0f
            },
            .id = 60
        },
        (DyeColor) {
            .name = "black_blue",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.06665646426952836f,
                .g = 0.09352726100263324f,
                .b = 0.1332085131842997f,
                .a = 1.0f
            },
            .id = 61
        },
        (DyeColor) {
            .name = "black_magenta",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.156181864191168f,
                .g = 0.05456225603304318f,
                .b = 0.15186264547581105f,
                .a = 1.0f
            },
            .id = 62
        },
        (DyeColor) {
            .name = "black_black",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.020276249520463124f,
                .g = 0.020276249520463124f,
                .b = 0.020276249520463124f,
                .a = 1.0f
            },
            .id = 63
        },
        (DyeColor) {
            .name = "black_white",
            .primary_dye = CLR_DYE_COLOR_BLACK,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.17261062707677471f,
                .g = 0.17261062707677471f,
                .b = 0.17261062707677471f,
                .a = 1.0f
            },
            .id = 64
        },
        (DyeColor) {
            .name = "white_red",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_RED,
            .color = (Color) {
                .r = 0.5155962896487515f,
                .g = 0.2463544061920076f,
                .b = 0.24270467989380443f,
                .a = 1.0f
            },
            .id = 65
        },
        (DyeColor) {
            .name = "white_yellow",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_YELLOW,
            .color = (Color) {
                .r = 0.7176234019070601f,
                .g = 0.5719406641200108f,
                .b = 0.34835984198499703f,
                .a = 1.0f
            },
            .id = 66
        },
        (DyeColor) {
            .name = "white_green",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_GREEN,
            .color = (Color) {
                .r = 0.3837587839814025f,
                .g = 0.47072619560382467f,
                .b = 0.29609795552457346f,
                .a = 1.0f
            },
            .id = 67
        },
        (DyeColor) {
            .name = "white_cyan",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_CYAN,
            .color = (Color) {
                .r = 0.44430476010449066f,
                .g = 0.5467513990701884f,
                .b = 0.5467513990701884f,
                .a = 1.0f
            },
            .id = 68
        },
        (DyeColor) {
            .name = "white_blue",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_BLUE,
            .color = (Color) {
                .r = 0.34391961390042436f,
                .g = 0.42554898524724505f,
                .b = 0.5467513990701884f,
                .a = 1.0f
            },
            .id = 69
        },
        (DyeColor) {
            .name = "white_magenta",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_MAGENTA,
            .color = (Color) {
                .r = 0.5155962896487515f,
                .g = 0.35133726221260553f,
                .b = 0.5095659785483663f,
                .a = 1.0f
            },
            .id = 70
        },
        (DyeColor) {
            .name = "white_black",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_BLACK,
            .color = (Color) {
                .r = 0.26840952091331366f,
                .g = 0.26840952091331366f,
                .b = 0.26840952091331366f,
                .a = 1.0f
            },
            .id = 71
        },
        (DyeColor) {
            .name = "white_white",
            .primary_dye = CLR_DYE_COLOR_WHITE,
            .secondary_dye = CLR_DYE_COLOR_WHITE,
            .color = (Color) {
                .r = 0.6993935721642928f,
                .g = 0.6993935721642928f,
                .b = 0.6993935721642928f,
                .a = 1.0f
            },
            .id = 72
        }
    };

    static std::vector<const DyeColor*> _base_dyes;

    void dyes_initialize()
    {
        for (int i = 0; i < CLR_BASE_DYES_COUNT; i++)
        {
            _base_dyes.push_back(&_dyes[i]);
        }
    }

    const std::array<const DyeColor, CLR_DYE_COLOR_COUNT>& get_dyes()
    {
        return _dyes;
    }

    const std::vector<const DyeColor*>& get_base_dyes()
    {
        return _base_dyes;
    }

    const DyeColor* get_base_dye_by_ids(uint8_t primary_dye, uint8_t secondary_dye)
    {
        for (auto& dye : _base_dyes)
        {
            if ((dye->primary_dye == primary_dye) && (dye->secondary_dye == secondary_dye))
            {
                return dye;
            }
        }

        return nullptr;
    }

    const DyeColor* get_dye_by_color(const Color& color)
    {
        for (auto& dye : _dyes)
        {
            if (dye.color == color)
            {
                return &dye;
            }
        }

        return nullptr;
    }

    const DyeColor* get_dye_by_ids(uint8_t primary_dye, uint8_t secondary_dye)
    {
        for (auto& dye : _dyes)
        {
            if ((dye.primary_dye == primary_dye) && (dye.secondary_dye == secondary_dye))
            {
                return &dye;
            }
        }

        return nullptr;
    }
}