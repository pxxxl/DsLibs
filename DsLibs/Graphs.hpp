#include <cstddef>;
#include <utility>;
#include <limits>;

namespace eds {

	using VRType = long long;

	constexpr size_t INFINITYS = std::numeric_limits<size_t>::max();
	constexpr size_t MAX_VERTEX_NUM = 20;

	enum class GraphKind
	{
		DG,
		DN,
		UDG,
		UDN
	};

	//邻接矩阵表示法

	template<typename _infoType>
	struct ArcCell {
		int adj;
		_infoType* info;
	};

	template<typename _infoType, typename _vertexType>
	struct MGraph {
		_vertexType vexs[MAX_VERTEX_NUM];
		ArcCell<_infoType> arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
		size_t vexnum, arcnum;
		GraphKind kind;
	};

	//邻接表表示法

	template<typename _infoType>
	struct ArcNode {
		int adjvex;
		ArcNode* nextarc;
		_infoType* info;
	};

	template<typename _infoType, typename _vertexType>
	struct VNode {
		_vertexType data;
		ArcNode<_infoType>* firstarc;
	};

	template<typename _infoType, typename _vertexType>
	struct ALGraph {
		VNode<_infoType, _vertexType> vertices[MAX_VERTEX_NUM];
		size_t vexnum, arcnum;
		GraphKind kind;
	};

	//十字链表表示法

	template<typename _infoType>
	struct ArcBox {
		int tailvex, headvex;
		ArcBox* hlink, * tlink;
		_infoType* info;
	};

	template<typename _infoType, typename _vertexType>
	struct VexNode {
		_vertexType data;
		ArcBox<_infoType>* firstin, * firstout;
	};

	template<typename _infoType, typename _vertexType>
	struct OLGraph {
		VexNode<_infoType, _vertexType> xlist[MAX_VERTEX_NUM];
		size_t vexnum, arcnum;
	};

	//临界多重表表示法

	enum class VisitIf {
		unvisited,
		visited
	};

	template<typename _infoType>
	struct EBox {
		VisitIf mark;
		int ivex, jvex;
		EBox* ilink, * jlink;
		_infoType* info;
	};

	template<typename _infoType, typename _vertexType>
	struct VexBox {
		_vertexType data;
		EBox<_infoType>* firstedge;
	};

	template<typename _infoType, typename _vertexType>
	struct AMLGraph {
		VexBox<_infoType, _vertexType> adjmulist[MAX_VERTEX_NUM];
		size_t vexnum, edgenum;
	};
}

