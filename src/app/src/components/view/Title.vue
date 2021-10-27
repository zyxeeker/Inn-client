<template>
    <div style="padding-left: 24px; padding-top: 24px;position: relative;">
        <n-h1 prefix="bar" align-text type="info">
            <div style="height:100%;display: flex;align-items: center;">
                <n-avatar :style="{marginRight:'10px',color: '#2080f0',backgroundColor: 'transparent'}" size="large">
                    <n-icon>
                        <TrailSignOutline/>
                    </n-icon>
                </n-avatar>
                <n-text type="info">{{ $route.params.title }}</n-text>
            </div>
        </n-h1>
        <n-space justify="start">
            <n-h2 style="margin-bottom: 8px;" align-text type="info">
                <n-text type="info">{{ $route.params.des }}</n-text>
            </n-h2>
        </n-space>
        <n-divider style="padding-right: 25px;margin-top: 5px;"/>
    </div>
</template>


<script>
import {TrailSignOutline} from "@vicons/ionicons5";

export default {
    name: "Title",
    components: {
        TrailSignOutline
    }
}
</script>

<style scoped>

</style>
