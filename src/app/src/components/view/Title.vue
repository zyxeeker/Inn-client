<template>
    <div style="padding-left: 24px; padding-top: 24px;position: relative;">
        <n-h1 align-text type="info">
            <div style="height:100%;display: flex;align-items: center;">
                <n-avatar round :style="{marginRight:'10px',backgroundColor: '#2080f0'}" size="large">
                    <n-icon color="white" size="20">
                        <ChatboxOutline/>
                    </n-icon>
                </n-avatar>
                <n-text type="info">{{ $route.params.title }}</n-text>
            </div>
        </n-h1>
        <n-h4 style="margin-bottom: 8px;margin-top: 8px;" align-text type="info">
            <n-text type="info">{{ $route.params.des }}</n-text>
        </n-h4>
        <n-divider style="padding-right: 25px;margin-top: 5px;"/>
    </div>
</template>


<script>
import {ChatboxOutline} from "@vicons/ionicons5";

export default {
    name: "Title",
    components: {
        ChatboxOutline
    }
}
</script>

<style scoped>

</style>
