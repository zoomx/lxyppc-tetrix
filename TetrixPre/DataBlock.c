
#include "IconBlock2.c"
#include "CharacterBlock.c"

//#define    BlockMCU    (BKMcu + 100)

const unsigned char* BlockMCU[68] = {
 Block_MCU0, Block_MCU1, Block_MCU2, Block_MCU3, Block_MCU4, Block_MCU5, Block_MCU6, Block_MCU7, Block_MCU8, Block_MCU9, Block_MCU10, Block_MCU11, Block_MCU12, Block_MCU13, Block_MCU14, Block_MCU15,
 Block_MCU16, Block_MCU17, Block_MCU18, Block_MCU19, Block_MCU20, Block_MCU21, Block_MCU22, Block_MCU23, Block_MCU24, Block_MCU25, Block_MCU26, Block_MCU27, Block_MCU28, Block_MCU29, Block_MCU30, Block_MCU31,
 Block_MCU32, Block_MCU33, Block_MCU34, Block_MCU35, Block_MCU36, Block_MCU37, Block_MCU38, Block_MCU39, Block_MCU40, Block_MCU41, Block_MCU42, Block_MCU43, Block_MCU44, Block_MCU45, Block_MCU46, Block_MCU47,
 Block_MCU48, Block_MCU49, Block_MCU50, Block_MCU51, Block_MCU52, Block_MCU53, Block_MCU54, Block_MCU55, Block_MCU56, Block_MCU57, Block_MCU58, Block_MCU59, Block_MCU60, Block_MCU61, Block_MCU62, Block_MCU63,
 Block_MCU64, Block_MCU65, Block_MCU66, Block_MCU67, /*Block_MCU68, Block_MCU69, Block_MCU70, Block_MCU71, Block_MCU72, Block_MCU73, Block_MCU74, Block_MCU75, Block_MCU76, Block_MCU77, Block_MCU78, Block_MCU79,
 Block_MCU80, Block_MCU81, Block_MCU82, Block_MCU83, Block_MCU84, Block_MCU85, Block_MCU86, Block_MCU87, Block_MCU88, Block_MCU89, Block_MCU90, Block_MCU91, Block_MCU92, Block_MCU93, Block_MCU94, Block_MCU95,
 Block_MCU96, Block_MCU97, Block_MCU98, Block_MCU99, Block_MCU100, Block_MCU101, Block_MCU102, Block_MCU103, Block_MCU104, Block_MCU105, Block_MCU106, Block_MCU107, Block_MCU108, Block_MCU109, Block_MCU110, Block_MCU111,
 Block_MCU112, Block_MCU113, Block_MCU114, Block_MCU115, Block_MCU116, Block_MCU117, Block_MCU118, Block_MCU119, Block_MCU120, Block_MCU121, Block_MCU122, Block_MCU123, Block_MCU124, Block_MCU125, Block_MCU126, Block_MCU127,
 Block_MCU128, Block_MCU129, Block_MCU130, Block_MCU131, Block_MCU132, Block_MCU133, Block_MCU134, Block_MCU135, Block_MCU136, Block_MCU137, Block_MCU138, Block_MCU139, Block_MCU140, Block_MCU141, Block_MCU142, Block_MCU143,
 Block_MCU144, Block_MCU145, Block_MCU146, Block_MCU147, Block_MCU148, Block_MCU149, Block_MCU150, Block_MCU151, Block_MCU152, Block_MCU153, Block_MCU154, Block_MCU155, Block_MCU156, Block_MCU157, Block_MCU158, Block_MCU159,
 Block_MCU160, Block_MCU161, Block_MCU162, Block_MCU163, Block_MCU164, Block_MCU165, Block_MCU166, Block_MCU167, Block_MCU168, Block_MCU169, Block_MCU170, Block_MCU171, Block_MCU172, Block_MCU173, Block_MCU174, Block_MCU175,
 Block_MCU176, Block_MCU177, Block_MCU178, Block_MCU179, Block_MCU180, Block_MCU181, Block_MCU182, Block_MCU183, Block_MCU184, Block_MCU185, Block_MCU186, Block_MCU187, Block_MCU188, Block_MCU189, Block_MCU190, Block_MCU191,
 Block_MCU192, Block_MCU193, Block_MCU194, Block_MCU195, Block_MCU196, Block_MCU197, Block_MCU198, Block_MCU199, Block_MCU200, Block_MCU201, Block_MCU202, Block_MCU203, Block_MCU204, Block_MCU205, Block_MCU206, Block_MCU207,
 Block_MCU208, Block_MCU209, Block_MCU210, Block_MCU211, Block_MCU212, Block_MCU213, Block_MCU214, Block_MCU215, Block_MCU216, Block_MCU217, Block_MCU218, Block_MCU219, Block_MCU220, Block_MCU221, Block_MCU222, Block_MCU223,
 Block_MCU224, Block_MCU225, Block_MCU226, Block_MCU227, Block_MCU228, Block_MCU229, Block_MCU230, Block_MCU231, Block_MCU232, Block_MCU233, Block_MCU234, Block_MCU235, Block_MCU236, Block_MCU237, Block_MCU238, Block_MCU239,
 Block_MCU240, Block_MCU241, Block_MCU242, Block_MCU243, Block_MCU244, Block_MCU245, Block_MCU246, Block_MCU247, Block_MCU248, Block_MCU249, Block_MCU250, Block_MCU251, Block_MCU252, Block_MCU253, Block_MCU254, Block_MCU255,
 Block_MCU256, Block_MCU257, Block_MCU258, Block_MCU259, Block_MCU260, Block_MCU261, Block_MCU262, Block_MCU263, Block_MCU264, Block_MCU265, Block_MCU266, Block_MCU267, Block_MCU268, Block_MCU269, Block_MCU270, Block_MCU271,
 Block_MCU272, Block_MCU273, Block_MCU274, Block_MCU275, Block_MCU276, Block_MCU277, Block_MCU278, Block_MCU279, Block_MCU280, Block_MCU281, Block_MCU282, Block_MCU283, Block_MCU284, Block_MCU285, Block_MCU286, Block_MCU287,
 Block_MCU288, Block_MCU289, Block_MCU290, Block_MCU291, Block_MCU292, Block_MCU293, Block_MCU294, Block_MCU295, Block_MCU296, Block_MCU297, Block_MCU298, Block_MCU299, Block_MCU300, Block_MCU301, Block_MCU302, Block_MCU303,
 Block_MCU304, Block_MCU305, Block_MCU306, Block_MCU307, Block_MCU308, Block_MCU309, Block_MCU310, Block_MCU311, Block_MCU312, Block_MCU313, Block_MCU314, Block_MCU315, Block_MCU316, Block_MCU317, Block_MCU318, Block_MCU319,
 Block_MCU320, Block_MCU321, Block_MCU322, Block_MCU323, Block_MCU324, Block_MCU325, Block_MCU326, Block_MCU327, Block_MCU328, Block_MCU329, Block_MCU330, Block_MCU331, Block_MCU332, Block_MCU333, Block_MCU334, Block_MCU335,
 Block_MCU336, Block_MCU337, Block_MCU338, Block_MCU339, Block_MCU340, Block_MCU341, Block_MCU342, Block_MCU343, Block_MCU344, Block_MCU345, Block_MCU346, Block_MCU347, Block_MCU348, Block_MCU349, Block_MCU350, Block_MCU351,
 Block_MCU352, Block_MCU353, Block_MCU354, Block_MCU355, Block_MCU356, Block_MCU357, Block_MCU358, Block_MCU359, Block_MCU360, Block_MCU361, Block_MCU362, Block_MCU363, Block_MCU364, Block_MCU365, Block_MCU366, Block_MCU367,
 Block_MCU368, Block_MCU369, Block_MCU370, Block_MCU371, Block_MCU372, Block_MCU373, Block_MCU374, Block_MCU375, Block_MCU376, Block_MCU377, Block_MCU378, Block_MCU379, Block_MCU380, Block_MCU381, Block_MCU382, Block_MCU383,
 Block_MCU384, Block_MCU385, Block_MCU386, Block_MCU387, Block_MCU388, Block_MCU389, Block_MCU390, Block_MCU391, Block_MCU392, Block_MCU393, Block_MCU394, Block_MCU395, Block_MCU396, Block_MCU397, Block_MCU398, Block_MCU399,
 Block_MCU400, Block_MCU401, Block_MCU402, Block_MCU403, Block_MCU404, Block_MCU405, Block_MCU406, Block_MCU407, Block_MCU408, Block_MCU409, Block_MCU410, Block_MCU411, Block_MCU412, Block_MCU413, Block_MCU414, Block_MCU415,
 Block_MCU416, Block_MCU417, Block_MCU418, Block_MCU419, Block_MCU420, Block_MCU421, Block_MCU422, Block_MCU423, Block_MCU424, Block_MCU425, Block_MCU426, Block_MCU427, Block_MCU428, Block_MCU429, Block_MCU430, Block_MCU431,
 *///Block_MCU432, Block_MCU433, Block_MCU434, Block_MCU435, Block_MCU436, Block_MCU437, Block_MCU438, Block_MCU439, Block_MCU440, Block_MCU441, Block_MCU442, Block_MCU443, Block_MCU444, Block_MCU445, Block_MCU446, Block_MCU447,
 //Block_MCU448, Block_MCU449, Block_MCU450, Block_MCU451, Block_MCU452, Block_MCU453, Block_MCU454, Block_MCU455, Block_MCU456, Block_MCU457, Block_MCU458, Block_MCU459, Block_MCU460, Block_MCU461, Block_MCU462, Block_MCU463,
 //Block_MCU464, Block_MCU465, Block_MCU466, Block_MCU467, Block_MCU468, Block_MCU469, Block_MCU470, Block_MCU471, Block_MCU472, Block_MCU473, Block_MCU474, Block_MCU475, Block_MCU476, Block_MCU477, Block_MCU478, Block_MCU479,
 //Block_MCU480, Block_MCU481, Block_MCU482, Block_MCU483, Block_MCU484, Block_MCU485, Block_MCU486, Block_MCU487, Block_MCU488, Block_MCU489, Block_MCU490, Block_MCU491, Block_MCU492, Block_MCU493, Block_MCU494, Block_MCU495,
 //Block_MCU496, Block_MCU497, Block_MCU498, Block_MCU499,
};
