package main

import (
	"fmt"
)

type CreativeListResult struct {
	ShowType            int    `json:"show_type"`
	Abstract            string `json:"abstract"`
	AdType              int    `json:"ad_type"`
	Brand               string `json:"brand"`
	CompanyName         string `json:"company_name"`
	CreateTime          string `json:"create_time"`
	CreativeMd5         string `json:"creative_md5"`
	Industry1           int    `json:"industry_1"`
	Industry2           int    `json:"industry_2"`
	Industry3           int    `json:"industry_3"`
	IndustryNetworkType int    `json:"industry_network_type"`
	Material            []struct {
		MaterialType int    `json:"material_type"`
		Link         string `json:"link"`
		Height       int    `json:"height"`
		Width        int    `json:"width"`
	} `json:"material"`
	Media          string `json:"media"`
	ModifyTime     string `json:"modify_time"`
	Platform       int    `json:"platform"`
	Product        string `json:"product"`
	Title          string `json:"title"`
	LandingpageURL string `json:"landingpage_url"`
	Type           int    `json:"type"`
}

func test(num *string) {
	fmt.Println(num)
}

func main() {
	common.ESClient.Init(&config.ESConfig{
		Cluster: []string{"http://"},
		Index:   "admonitor_creative_op",
		Type:    "admonitor_creative_op_type",
	})
	//res, err := common.ESClient.BoolSearch(1, 1, "2s", elastic.NewBoolQuery().Must(elastic.NewTermsQuery("type", *utils.MakeInterfaceSlice([]int32{1, 2, 3})...)))
	//if err != nil {
	//	fmt.Println(err.Error())
	//}
	//if res.Hits.TotalHits > 0 {
	//	fmt.Printf("Found a total %d \n", res.Hits.TotalHits)
	//
	//	for _, hit := range res.Hits.Hits {
	//		var dat CreativeListResult
	//		err := json.Unmarshal(*hit.Source, &dat) //另外一种取数据的方法
	//		if err != nil {
	//			panic(err)
	//		}
	//		fmt.Println(dat)
	//	}
	//} else {
	//	fmt.Printf("Found no \n")
	//}
		fmt.Println(common.ESClient.Add(
			"3",
			//`{"landingpage_url": "https://ku.m.taobao.com/bus?keyword=&catid=50006856&refpid=tt_26632548_22732013_127700028&crtid=1318618366&itemid=576102836705&adgrid=1237731825&qword=%E6%B5%B4%E5%AE%A4%E8%A7%92%E6%9E%B6&pagetype=2&partnerid=&prodtype=2&sbid=%3B%3B%2C%3B41185%2C41187%2C99094%2C41191%2C41193%2C41195%2C41278&nick=%5Cu6D1B%5Cu9633%5Cu5927%5Cu5168&qtype=7&tagvalue=151140798_0_471318251425&mkey=T0RZMU1UWTJNREkzTWpBME56VXk=&clk1info=1278931227%2C88%2CMfX%2BC/ezZjGcLDoVVL6n3fQd7kRsTpyie/YYGmjIKkhe9qQVLHWmDtDPfjvdk28izUutJ82l8dqiLEflksyfaQ==&isf=0&appkey=24542362&packageName=com.jifen.qukan&backURL=&visa=&bc_fl_src=tanx_k2_127700028_0b0c4bcb00015c9d6d8657df002b4657&clk1=b26fd5cddea170a6ca64dc3939086ad8", "show_type": 2, "abstract": "\u4eb2\u4f60\u60f3\u8981\u7684\u6211\u4eec\u90fd\u77e5\u9053\u8d85\u503c\u60ca\u559c\u6839\u672c\u505c\u4e0d\u4e0b\u6765", "ad_type": 1, "brand": "", "company_name": "", "create_time": "2019-03-29 15:47:02", "creative_md5": "001facb80cc90d75525c33eba0eb10ef", "industry_1": 1902, "industry_2": 190201, "industry_3": 19020101, "industry_network_type": 1, "material": [{"material_type": 1, "link": "http://tosv.byted.org/obj/creative-img/RM1b3pa7SS8VDZ", "height": 0, "width": 0}, {"material_type": 1, "link": "http://tosv.byted.org/obj/creative-img/RM1b3ppaBml7C", "height": 0, "width": 0}, {"material_type": 1, "link": "http://tosv.byted.org/obj/creative-img/RM1b3q2IAkzNk3", "height": 0, "width": 0}], "media": "\u8da3\u5934\u6761", "modify_time": "2019-04-01 15:47:02", "platform": 2, "product": "", "title": "\u536b\u751f\u95f4\u6d74\u5ba4\u7f6e\u7269\u67b6\u63a8\u8f66\u6536\u7eb3\u67dc\u5851\u6599\u50a8\u7269\u8138\u76c6\u67b6", "type": 2}`))
			//`{"landingpage_url": "https://sem.17zhuangxiu.cn/1125.html?channel=semsinafuyi&wh190107-2&iclicashsid=Y5jevlmaE-sLh8GVCvVYNN8839F_zhf9SRCD_d8o&icliideaid=rKSerKRtJl", "show_type": 1, "abstract": "", "ad_type": 1, "brand": "", "company_name": "", "create_time": "2019-02-28 15:47:02", "creative_md5": "002e11730310b3ffc79a5fba962ec804", "industry_1": 1909, "industry_2": 190903, "industry_3": 19090302, "industry_network_type": 1, "material": [{"material_type": 1, "link": "http://tosv.byted.org/obj/creative-img/RLqC2nk9j0LAJx", "height": 0, "width": 0}], "media": "\u8da3\u5934\u6761", "modify_time": "2019-04-04 15:47:02", "platform": 2, "product": "", "title": "20\u5e74\u5305\u5de5\u5934\u900f\u97322019\u5e74\u6700\u65b0\u5168\u5c4b\u88c5\u4fee\u62a5\u4ef7\u5355", "type": 1}`))
	`{"landingpage_url": "http://axela.changan-mazda.com.cn/market/m/axela2018cuxiao3/?utm_source=AiQiYi&utm_content=xiangwangdeshenghuo2shipinbofangkuangnei&utm_medium=yidongduanxiangwangdeshenghuo215miaotiepianzhengpianhuaxuzhongjiantie15liuliang&utm_campaign=20925895&smt_cp=105908&smt_pl=2435229&smt_md=1118", "show_type": 1, "abstract": "", "ad_type": 3, "brand": "", "company_name": "", "create_time": "2019-02-25 15:47:02", "creative_md5": "67372fbaecf8739a84dadafca23336c0", "industry_1": 1916, "industry_2": 191601, "industry_3": 19160102, "industry_network_type": 0, "material": [{"material_type": 2, "link": "http://tosv.byted.org/obj/tos-cn-v-0000/2a1ba732152d4fb6998206f98ec2a6f7", "height": 0, "width": 0}], "media": "\u7231\u5947\u827a", "modify_time": "2019-04-06 15:47:02", "platform": 2, "product": "", "title": "\u65b0Mazda3 AXELA \u6602\u514b\u8d5b\u62c9 \u667a\u6167\u6089\u5fc3 \u9047\u89c1\u5b89\u5168\u8d34\u5fc3", "type": 3}`))
}
